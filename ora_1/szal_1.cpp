#include <iostream>
#include <thread>
 
void szal(int i, int k) {
  for (int j = 0; j < 1000; ++j) {
    std::cout << i << " " << k;
  }
}
 
int main() {
  std::thread t1{szal, 1, 0};       /* szal(1); */
  std::thread t2{szal, 2, 3};       /* szal(2); */
    /* ... */
    t1.join();
    t2.join();
}
