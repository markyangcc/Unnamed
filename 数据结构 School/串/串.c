/*  6-1 字符串的替换操作replace (String &s, String &t, String &v)是指：
若t是s的子串，则用串v替换串t在串s中的所有出现；若t不是s的子串，则串s不变。         
例如，若串s为“ aabbabcbaabaaacbab ”，串t为“ bab ”，串v为“ abdc ”，则执行replace操作后，串s中的结果为“aababdccbaabaaacabdc”。
 s= "我和我的祖国"；   t="祖国"； v=“家人” v替换t后，成为s=“我和我的家人”
试利用字符串的基本运算实现这个替换操作。

6-2 编写一个算法frequency，统计在一个输入字符串中各个不同字符出现的频度。用适当的测试数据来验证这个算法。 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TXTSIZE 50

int search(char *txt, char *pat) //Naive Pattern Searching and replacement algorithm
{
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    const int maxfoundnum = txt_len / pat_len;
    //原来想用 maxfoundnum 以节省空间，但是又需要static保存数组地址，static限定的数组不允许大小为变量，而且strlen()无法在编译时起作用

    int result_matched = 0;
    // int foundindex = (int)malloc(sizeof(int) * maxfoundnum + sizeof(int));
    static int foundindex[TXTSIZE];

    for (int i = 0; i <= txt_len - pat_len; i++) //travel every possible pattern
    {
        int j;

        for (j = 0; j < pat_len; j++) //check if current indx match
            if (txt[i + j] != pat[j])
                break;

        if (j == pat_len)
        {

            printf("\nPattern matching successful!\n");
            printf("The pattern string appeared at index %d\n", i);

            foundindex[++result_matched] = i;
        }
    }
    foundindex[0] = result_matched;

    return foundindex;
}

void replace(char *txt, char *pat, char *replacetxt, int foundindex)
{
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int replacetxt_len = strlen(replacetxt);

    if (TXTSIZE < txt_len + (replacetxt_len - pat_len) * result_matched)
    {
        printf("String array overflow.\n");
        exit(EXIT_FAILURE);
    }

}

/* Driver program to test above function */
int main(void)
{
    char txt[TXTSIZE] = "aabbabcbaabaaacbab";
    char pat[] = "bab";
    char replacetxt[] = "abdc";

    int *foundindex = search(txt, pat);

    for (int i = 0; i < *foundindex; i++)
    {
        printf("%d\t", *(foundindex + i + 1));
    }

    replace(txt, pat, replacetxt, foundindex);

    return 0;
}
