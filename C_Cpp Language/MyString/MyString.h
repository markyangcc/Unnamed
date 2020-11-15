#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <cstring>
#include <iostream>

class MyString {
 private:
  int len;
  char *str;

 public:
  MyString();
  explicit MyString(const char *st);
  ~MyString();

  MyString MyStrcat(MyString &st);
  void display();
};

#endif