# include <ctype.h>
#include <math.h>

int mystrlen(char *s2)
{
    char *s2_begin = s2;

    while (*s2 != '\0')
    {
        if (!isdigit(*s2))
            return 0;

        s2++;
    }
    int len = abs(s2 - s2_begin);
    return len;
}
