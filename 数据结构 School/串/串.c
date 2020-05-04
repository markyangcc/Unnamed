/*  6-1 字符串的替换操作replace (String &s, String &t, String &v) (cpp)是指：
若t是s的子串，则用串v替换串t在串s中的所有出现；若t不是s的子串，则串s不变。         
例如，若串s为“ aabbabcbaabaaacbab ”，串t为“ bab ”，串v为“ abdc ”，则执行replace操作后，串s中的结果为“aababdccbaabaaacabdc”。
 s= "我和我的祖国"；   t="祖国"； v=“家人” v替换t后，成为s=“我和我的家人”
试利用字符串的基本运算实现这个替换操作。*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TXTSIZE 50

int *search(char *txt, char *pat) //Naive Pattern Searching and replacement algorithm
{
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    // const int maxfoundnum = txt_len / pat_len;
    //原来想用 maxfoundnum 以节省空间，但是又需要static保存数组地址，static限定的数组不允许大小为变量，
    // 而且strlen()无法在编译时起作用,只能在运行时才起作用，没有想到更好方法，故使用宏常量TXTSIZE，造成一定的空间浪费

    int result_matched = 0; //get how many result matched in string txt
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
    foundindex[0] = result_matched; //one function can only return one value,so make the must needed variable store in array

    return foundindex;
}

void replace(char *txt, char *pat, char *replacetxt, int *foundindex, int count)
{

    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int replacetxt_len = strlen(replacetxt);

    if (TXTSIZE < txt_len + (replacetxt_len - pat_len) * foundindex[0]) //check if array is enough for containing
    {
        printf("String array overflow.\n");
        exit(EXIT_FAILURE);
    }

    char temp[TXTSIZE];
    int i = 1; //i store the pattern appeared index(index 0 is used to count pattern appeared times)
    int j = 2; //j used to update pattern index, when we replace a pattern the index is changed in array
               //(index 0 is used to count pattern appeared times)

    while (count < foundindex[0])
    {
        strcpy(temp, txt + *(foundindex + i) + pat_len);        //copy string after found pattern to a temp array
        strcpy(txt + *(foundindex + i), replacetxt);            //replace pattern with replace text
        strcpy(txt + *(foundindex + i) + replacetxt_len, temp); //make string concatenation into updated txt
        i++;
        while (j <= *foundindex) //need to update other patterns' index, after replace one pattern
        {
            *(foundindex + j) += (replacetxt_len - pat_len);
            j++;
        }
        count++;
    }
    if (count > foundindex[0]) //optional Conditional judgment. Without it, the program will also end normally after execution
        return;
}

int main(void) // Driver program to test above function
{
    char txt[TXTSIZE] = "aabbabcbaabaaacbab";
    char pat[] = "bab";
    char replacetxt[] = "abdc";
    // char replacetxt[] = "p"; //Both effective

    int *foundindex = search(txt, pat);

    int count = 0; //count times when replacing patterns
    replace(txt, pat, replacetxt, foundindex, count);

    printf("\nReplaced string: ");
    puts(txt);

    return 0;
}
