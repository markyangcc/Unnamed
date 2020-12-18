/*编一程序，统计从键盘输入的命令行中第二个参数所包含的英文字符个数 */

#include <stdio.h>

int main(char argc, char *argv[])
{
    int count = 0;

    while (*argv[2] != '\0')
    {
        count++;
        *argv[2]++;
    }
    printf("Number of characters in second parameter:%d", count);
    
    return 0;
}
