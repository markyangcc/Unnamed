/*  6-1 字符串的替换操作replace (String &s, String &t, String &v)是指：
若t是s的子串，则用串v替换串t在串s中的所有出现；若t不是s的子串，则串s不变。         
例如，若串s为“aabbabcbaabaaacbab”，串t为“bab”，串v为“abdc”，则执行replace操作后，串s中的结果为“aababdccbaabaaacabdc”。
 s= "我和我的祖国"；   t="祖国"； v=“家人” v替换t后，成为s=“我和我的家人”
试利用字符串的基本运算实现这个替换操作。

6-2 编写一个算法frequency，统计在一个输入字符串中各个不同字符出现的频度。用适当的测试数据来验证这个算法。 */
// C program for Naive Pattern Searching algorithm 
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

void replace(char *txt, char *pat, char *replacetxt) //Naive Pattern Searching and replacement algorithm
{

    int txt_len = strlen(txt);
    int pat_len = strlen(pat);

    int foundindex[txt_len / pat_len]; //max size to store possible matched pattern index
    int result_matched = 0;

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

            foundindex[result_matched++] = i;
        }
    }

    int replacetxt_len = strlen(replacetxt);

    if (TXTSIZE < txt_len + (replacetxt_len - pat_len) * result_matched)
    {
        printf("String array overflow.\n");
        exit(EXIT_FAILURE);
    }

    

    for (int i = 0; i < result_matched; i++)
    {
        printf("%d\t", foundindex[i]);
    }
}

/* Driver program to test above function */
int main()
{
    char txt[TXTSIZE] = "aabbabcbaabaaacbab";
    char pat[] = "bab";
    char replacetxt[] = "abdc";
    replace(txt, pat, replacetxt);
    // search(pat, txt);
    return 0;
}
