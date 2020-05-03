/*  6-1 字符串的替换操作replace (String &s, String &t, String &v)是指：
若t是s的子串，则用串v替换串t在串s中的所有出现；若t不是s的子串，则串s不变。         
例如，若串s为“aabbabcbaabaaacbab”，串t为“bab”，串v为“abdc”，则执行replace操作后，串s中的结果为“aababdccbaabaaacabdc”。
 s= "我和我的祖国"；   t="祖国"； v=“家人” v替换t后，成为s=“我和我的家人”
试利用字符串的基本运算实现这个替换操作。

6-2 编写一个算法frequency，统计在一个输入字符串中各个不同字符出现的频度。用适当的测试数据来验证这个算法。 */
// C program for Naive Pattern Searching algorithm 
#include <stdio.h> 
#include <string.h> 

void search(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++) { 
		int j; 

		/* For current index i, check for pattern match */
		for (j = 0; j < M; j++) 
			if (txt[i + j] != pat[j]) 
				break; 

		if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			printf("Pattern found at index %d \n", i); 
	} 
} 

/* Driver program to test above function */
int main() 
{ 
	char txt[] = "AABAACAADAABAAABAA"; 
	char pat[] = "AABA"; 
	search(pat, txt); 
	return 0; 
} 
