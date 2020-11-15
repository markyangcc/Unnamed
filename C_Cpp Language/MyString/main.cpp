//义一个MyString类，实现两个字符串相加。要求定义类的数据对象为 char *， 实现 deep copy。
//不能使用 <string>,可以使用 <cstring>
//测试函数如下

#include "MyString.h"

int main() {
  MyString str1("Hello");
  MyString str2("World!");

  str1.MyStrcat(str2);

  str1.display();//output: "HelloWorld!"

  return 0;
}
