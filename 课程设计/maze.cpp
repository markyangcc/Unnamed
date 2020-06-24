#include <Windows.h>
#include <iostream>
#include <stack>

using namespace std;

//Position定义坐标
struct Position
{
	int row;
	int col;
};

//Maze类创建迷宫并寻找最短路径
class Maze
{
private:
	int row;  //迷宫的宽度
	int col;  //迷宫的高度
	int show; //1=演示寻径流程 或者 0=不演示寻径流程

	Position offset[4]; //上下左右的偏移量

	stack<Position> path; //存储路径的堆栈
	char **maze;		  //迷宫地图的数组
	char **mazeShow;	  //用来显示迷宫寻径结果的数组

public:
	Maze(int row, int col, int show);
	void ShowArray(char **array, int m, int n); //输出m*n的二维数组
	bool FindPath();							//寻找迷宫出口的方法
	void DrawPath();							//绘制迷宫的寻径结果
	void ShowDetail(Position here);				//展示寻径的流程
};

//迷宫数据的输入和偏移量的初始化
Maze::Maze(int row, int col, int show)
{
	this->row = row;
	this->col = col;
	this->show = show;

	//初始化maze二维数组
	maze = new char *[row + 2];
	for (int i = 0; i < row + 2; ++i)
		maze[i] = new char[col + 2];

	//初始化mazeShow二维数组
	mazeShow = new char *[row + 2];
	for (i = 0; i < row + 2; ++i)
		mazeShow[i] = new char[col + 2];

	//对偏移量进行初始化
	offset[0].row = 0;
	offset[0].col = 1; //向右
	offset[1].row = 1;
	offset[1].col = 0; //向下
	offset[2].row = 0;
	offset[2].col = -1; //向左
	offset[3].row = -1;
	offset[3].col = 0; //向上

	//输入迷宫的地图数据
	int mazeData[10][10] =
		{
			{0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
			{0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
			{0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
			{0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
			{0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
			{0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
			{0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
			{1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
		};

	//将迷宫数据导入迷宫数组中
	for (int ii = 0; ii < row; ii++)
	{
		for (int jj = 0; jj < col; jj++)
		{
			maze[ii + 1][jj + 1] = mazeData[ii][jj];
		}
	}

	//在迷宫外增加一圈障碍物
	for (int r = 0; r <= row + 1; r++)
	{
		maze[0][r] = maze[row + 1][r] = 1;
	}
	for (int c = 0; c <= col + 1; c++)
	{
		maze[c][0] = maze[c][col + 1] = 1;
	}

	for (int iii = 0; iii < row + 2; iii++)
	{
		for (int jjj = 0; jjj < col + 2; jjj++)
		{
			mazeShow[iii][jjj] = maze[iii][jjj];
		}
	}
	if (show)
	{
		for (int t = 0; t < 30; t++)
			cout << endl;
	}
	cout << endl
		 << "原始的迷宫地图：" << endl;
	ShowArray(maze, row + 2, col + 2);
}

//遍历输出二维数组
void Maze::ShowArray(char **array, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

//显示具体的寻径流程
void Maze::ShowDetail(Position here)
{
	Sleep(500);
	for (int t = 0; t < 30; t++)
		cout << endl;
	char me = 2;
	for (int i = 0; i < row + 2; i++)
	{
		for (int j = 0; j < col + 2; j++)
		{
			if (i == here.row && j == here.col)
			{
				cout << me << " ";
			}
			else
			{
				cout << maze[i][j] << " ";
			}
		}
		cout << endl;
	}
}

//寻找从位置(1，1)到出口(m,m)的路径
//如果成功则true，否则返回false
bool Maze::FindPath()
{
	Position here;
	here.row = 1;
	here.col = 1;

	maze[1][1] = 1;

	int option = 0;		//选择的移动方向
	int LastOption = 3; //最后一个方向选择

	//寻找一条路径
	while (here.row != row || here.col != col)
	{
		//寻找并且移动到一个相邻的位置
		int r, c;
		while (option <= LastOption)
		{
			r = here.row + offset[option].row;
			c = here.col + offset[option].col;

			if (maze[r][c] == 0)
				break;
			option++;
		}

		//是否找到一个相邻的位置
		if (option <= LastOption)
		{
			//移动到maze[r][c]
			//将当前位置压入堆栈
			path.push(here);
			here.row = r;
			here.col = c;

			//设置障碍物以阻止再次访问
			maze[r][c] = 4;
			option = 0;
		}
		else
		{
			//没有可用的相邻位置，回溯上一个节点
			if (path.empty())
				return false;

			Position next = path.top();
			path.pop();

			option = 0;

			here = next;
		}
		if (show)
		{
			ShowDetail(here);
		}
	}
	return true;
}

//绘制最终的寻径结果
void Maze::DrawPath()
{
	Position temp;
	while (!path.empty())
	{
		temp = path.top();
		path.pop();
		mazeShow[temp.row][temp.col] = '+';
	}

	mazeShow[row][col] = 3;
	mazeShow[1][1] = 2;

	if (show)
	{
		for (int t = 0; t < 30; t++)
			cout << endl;
	}
	cout << endl
		 << "寻径后的迷宫地图：" << endl;
	ShowArray(mazeShow, row + 2, col + 2);
}

void main()
{
	cout << "欢迎来到迷宫老鼠1.0版本!\n是否需要显示迷宫寻径的具体流程？(Y/N)" << endl;
	char input;
	cin >> input;
	int show; //是否展示迷宫寻径流程，1展示，0不展示
	if (input == 'Y' || input == 'y')
		show = 1;
	else if (input == 'N' || input == 'n')
		show = 0;
	else
		return;

	Maze *myMaze = new Maze(10, 10, show);
	myMaze->FindPath();
	myMaze->DrawPath();
}
