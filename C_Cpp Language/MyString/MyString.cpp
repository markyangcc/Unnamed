#include "MyString.h"

MyString::MyString() {
  str = new char[1];
  str[0] = '\0';
  len = 0;
}

MyString::MyString(const char *st) {

  len = strlen(st);
  str = new char[len + 1];
  strcpy(str, st);
}

MyString::~MyString() = default;

MyString MyString::MyStrcat(MyString &st) {

  len = len + st.len;
  strcat(str, st.str);
  return (*this);
}

void MyString::display() {

  for (int i = 0; i < len; ++i)
	std::cout << str[i];
}

