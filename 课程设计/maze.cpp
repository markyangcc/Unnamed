#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <stack>

using namespace std;
/* using std::cin;
using std::cout;
using std::endl;
using std::stack; */

typedef struct
{
    int row;
    int col;
} POSITION;

const POSITION maze_size = {30, 60};

int **const maze = new int *[maze_size.row + 2];

stack<POSITION> path;

POSITION offset[4]; //direction

void init();
void randomMaze();
bool findPath();
void outputMaze();
void setPathOnMaze();

int main()
{
    printf("%d", maze_size.row);
    printf("\n-------------------------\n");
    srand((unsigned int)time(NULL));

    init();
    randomMaze();

    //打印随机生成的迷宫
    /* for (int i = 0; i < maze_size.row; i++)
	{
		for (int j = 0; j < maze_size.col; j++)
		{
			printf("%2d", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n====================\n"); */

    cout << "Init Maze: " << endl;
    outputMaze();

    cout << endl
         << endl;

    if (findPath())
    {
        cout << "Find a path:" << endl;
        setPathOnMaze();
        outputMaze();
    }
    else
    {
        cout << "No path" << endl;
    }

    return 0;
}

void init()
{
    //偏移
    offset[0].row = 0;
    offset[0].col = 1; //right
    offset[1].row = 1;
    offset[1].col = 0; //down
    offset[2].row = 0;
    offset[2].col = -1; //left
    offset[3].row = -1;
    offset[3].col = 0; //up

    for (int i = 0; i < maze_size.row + 2; i++) //利用一维数组创建二维数组
    {
        maze[i] = new int[maze_size.col + 2];
    }
}

//地图范围1 - maze_size(从0开始) 有围墙
void randomMaze()
{
    int i, j, rate;

    for (i = 0; i < maze_size.row + 2; i++)
    {
        for (j = 0; j < maze_size.col + 2; j++)
        {
            //设置围墙
            if ((i == 0) || (i == maze_size.row + 1) || (j == 0) || (j == maze_size.col + 1))
            {
                maze[i][j] = 1;
            }
            else
            {
                rate = rand() % 10 + 1; //生成1-10之间的随机数
                if (rate <= 2)          //迷宫的难度，数字越小难度越低
                {
                    maze[i][j] = 1; //随机生成障碍
                }
                else
                {
                    maze[i][j] = 0;
                }
            }
        }
    }
    //保证起点与终点不存在障碍
    maze[1][1] = maze[maze_size.row][maze_size.col] = 0;
}

void outputMaze()
{
    int i, j;
    for (i = 0; i < maze_size.row + 2; i++)
    {
        for (j = 0; j < maze_size.col + 2; j++)
        {
            if (maze[i][j] == 1)
            {
                cout << "#";
            }
            else if ((maze[i][j] == 0) || (maze[i][j] == 3))
            //else if (maze[i][j] == 0)
            {
                cout << " ";
            }
            else //为设置为非0，1，3的加颜色
            {
                HANDLE hOut;
                hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "#";
                SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        cout << endl;
    }
}

bool findPath()
{
    POSITION here; //当前位置
    here.row = here.col = 1;

    maze[1][1] = 3; //放置障碍，防止回来
    int option = 0; //next step
    const int lastOption = 3;

    //find a path
    while (here.row != maze_size.row || here.col != maze_size.col)
    {
        //not reach the edge(maze_size是围墙)
        int r, c;
        while (option <= lastOption)
        {
            r = here.row + offset[option].row;
            c = here.col + offset[option].col;
            if (maze[r][c] == 0)
            {
                break;
            }
            option++; //next choice
                      //outputMaze();
                      //printf("\n\n");
        }

        //相邻的位置能走？
        if (option <= lastOption)
        {
            path.push(here);
            here.row = r;
            here.col = c;
            maze[r][c] = 3; //走过了，设置为障碍
            option = 0;     //重置option
        }
        else
        {
            if (path.empty()) //栈空，证明无路可走了
            {
                return false;
            }
            //go back
            maze[here.row][here.col] = 3; //此路不可通
            path.pop();                   //TODO:优化而添加的代码
            here = path.top();            //这里可以优化，栈顶的元素已经证明是死路，不需要在测试一遍了，直接pop()掉即可
            path.pop();
            option = 0;
        }
    }
    maze[maze_size.row][maze_size.col] = 2; //不要设置为0，1，3代表特殊含义的数字都行

    return true;
}
void setPathOnMaze() //后面为栈里面的加颜色
{
    POSITION pos;
    while (!path.empty())
    {
        pos = path.top();
        path.pop();
        maze[pos.row][pos.col] = 2;
    }
}
