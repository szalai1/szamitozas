#include <cmath>
#include <functional>
#include <iostream>

// functor megoldas a Functiont kell peldanyositani aztan a peldanynak van ()-e.
class Function {
public:
  static int i;
  int id;
  Function() {
    id = i;
    i +=1;
    std::cout << "LETREJON " << id << std::endl;
  }
  Function(const Function& f) {
    id = i;
    i+=1;
    std::cout << f.id << " COPY " << id << std::endl;
  }
  double operator()(double x) const {
    return x;
  }

  int get_id() const { return id;}
  ~Function() {
    std::cout << "FUNCTION MEGHALT " << id  << std::endl;
  }
};

int Function::i = 0;
std::function<double(double)> logged_func(const Function fg, std::string str) {
  // copy a lambdanak az = miatt  copy 2.
  std::cout << "fg(lambdana kivul): " << fg.get_id() << std::endl;
  return  [=](double x) {
    std::cout << "fg(lambdanbelul): " << fg.get_id() << std::endl;  
      std::cout << " Log: " << str << "(" << x << ")" << std::endl;
      return fg(x);
    };
  // itt meghal a masolt az logged_function parametere tehat az 1-es   
}

int main() {
  std::function<double(double)> logged_sin;
  // a {} block azert kell hogy az ff destruktora meghivodjon
  {
    // itt construktor 0.
    Function ff = Function();
    // copy construktor az fg-nek 1.
    logged_sin = logged_func(ff, "ff");
    // meghal 0.
  }
    logged_sin(1.2);
}
