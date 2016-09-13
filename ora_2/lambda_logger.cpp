#include <cmath>
#include <functional>
#include <iostream>

class Function {
public:
  static int i;
  int id;
  Function() {
    id = i;
    i +=1;
    std::cout << "letrejon " << id << std::endl;
  }
  Function(const Function& f) {
    id = i;
    i+=1;
    std::cout << f.id << " cpoy " << id << std::endl;
  }
  double operator()(double x) {
    return x;
  }
  ~Function() {
    std::cout << "FUNCTION MEGHALT " << id  << std::endl;
  }
};

int Function::i = 0;
std::function<double(double)> logged_func(const Function fg, std::string str) 
{
  std::cout << "1." << std::endl;
  return  [=](double x) 
    {
      std::cout << " Log: " << str << "(" << x << ")" << std::endl;
      return fg(x);
    };

}

int main() {
  
  std::function<double(double)> logged_sin;
  {
    Function ff = Function();
    logged_sin = logged_func(ff, "ff");
    //std::cout << "2." << std::endl;
  }
    logged_sin(1.2);
    //std::cout << "3." << std::endl;
}
