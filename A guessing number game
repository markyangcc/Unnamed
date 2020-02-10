//This a guessing number game, write it for fun

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1;
#define MAX 100;

int rand_num(void); //Generate a random number from 1 to 100
int guess_num(int r_num, int value);
void new_range(int r_num, int value, int *min, int *max);

int main(void)
{
    int r_num;
    int value;
    int count_times_main;

    r_num = rand_num();

    printf("Enter a number from 1 to 100, I'll try to guess it:");
    scanf("%d", &value);
    while (getchar() != '\n')
        continue;

    count_times_main = guess_num(r_num, value);

    printf("Total guess times: %d", count_times_main);

    return 0;
}

int rand_num(void)
{
    int r_num;
    srand((unsigned)(time(NULL)));
    r_num = rand() % 100 + 1;
    //printf(" The randomly generated num: %d\n", r_num);

    return r_num;
}

int guess_num(int r_num, int value)
{
    int count_times = 0; //猜测的次数
    int min = MIN;
    int max = MAX;

    while (1)
    {
        if (r_num == value)
        {
            printf("You are right.");
            count_times++;
            return count_times;
        }
        else
        {
            count_times++;
            new_range(r_num, value, &min, &max);
            printf("No. Offer you a hint.The range is %d to %d. Try again:", min, max);
            scanf("%d", &value);
            continue;
        }
    }
}

void new_range(int r_num, int value, int *min, int *max)
{
    if (value <= *max && value >= r_num)
    {
        *max = value; //更新右域，左域不用更新
    }
    else if (value >= *min && value <= r_num)
    {
        *min = value; //更新左域，右域不用更新
    }
}
