#include <iostream>
#include <string>
#include <functional>


class Function {
public:
  std::string operator()(std::string str) {
    return "{" + str + "}";
  }
};

void kiir(std::string str, std::string (*fn)(std::string)) {
  std::cout << " fn: " << fn  << "   *fn " << *fn << "  "  <<  (*fn)(str) << std::endl;
}

template<typename T >
void  kiir2(std::string str, T fn) {
  std::cout << fn(str) << std::endl;
  
}

std::string f1(std::string str) {
  return "> " + str + "<";
}

void f(int* i ) {
  std::cout << "i: " << i << std::endl;
}

int main() {
  Function x = Function();
  std::cout << x.operator()("dinnye") << std::endl;
  std::cout << x("banan") << std::endl;
  kiir("alma", &f1);
  kiir2("korte", &f1);
  kiir2("barack", x);
  int i = 5;
  f(&i);
  std ::cout << "===============================\n lambda\n ============================\n\n";
  kiir2("szilva", [](std::string str){return "~~~" + str + "~~~~";});
  return 1;
}
