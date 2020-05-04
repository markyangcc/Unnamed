
### 字符串暴力匹配算法
int *search(char *txt, char *pat) //Naive Pattern Searching and replacement algorithm
### 字符串替换算法
void replace(char *txt, char *pat, char *replacetxt, int *foundindex, int count)

txt---正文
pat---模式字符串，即关键词
replacetxt---替换词
foundindex---存储pat在txt中位置和总计匹配到的项数
count---计数器