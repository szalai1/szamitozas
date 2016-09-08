#include <iostream>
#include <thread>
#include <vector>
 
void szal(int i) {
    std::cout << "Hello a szalbol: " << i << std::endl;
}
 
int main() {
    std::vector<std::thread> szalak;
    
    for (int i = 1; i <= 20; ++i)
        szalak.push_back(std::thread{szal, i}); // szal(i)
    
    for (auto & szal : szalak)
        szal.join();
}
