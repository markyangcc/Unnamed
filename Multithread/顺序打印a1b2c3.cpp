#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int n = 26;
int i = 0;
mutex mtx;
bool char_turn;
condition_variable cv;

void printchar() {
  unique_lock<mutex> ulock(mtx);

  while (i < n) {
    // void wait( std::unique_lock<std::mutex>& lock, Predicate pred );
    // Predicate 是离散数学的概念, 理解为返回bool类型的函数, 返回false继续 block
    cv.wait(ulock, [] { return char_turn; });

    cout << i << " ";
    char_turn = false;
    cv.notify_all();
  }
}

void printnum() {
  unique_lock<mutex> ulock(mtx);

  while (i < n) {
    cv.wait(ulock, [] { return !char_turn; });

    cout << (char)(i + 'a');
    char_turn = true;
    i++;
    cv.notify_all();
  }
}

int main() {
  thread a(printchar);
  thread b(printnum);
  //等这两个函数执行完，main再退出，不可以detach
  a.join();
  b.join();

  return 0;
}