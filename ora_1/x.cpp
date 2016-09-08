#include <iostream>
#include <functional>

void kiir(std::string s, std::function<std::string(std::string)>  dekorator) {
  std::cout << dekorator(s) << std::endl;
}

std::string zarojelez(std::string str) {
  return "(" + str + ")";
}

std::function<std::string(std::string)> zarojelezoGenerator(std::string zarojel, std::string zarojel2) {
  return [zarojel,zarojel2](std::string x) {
    return zarojel + x + zarojel2;
  };
}

int main() {
  std::function<std::string(std::string)> cakkozo = zarojelezoGenerator("{", "}");
  kiir("alma", zarojelezoGenerator("< ", " >"));
  kiir("korte",  zarojelezoGenerator("==== ", " ===="));
  kiir("dinnye",  zarojelezoGenerator("~~~\t", "\t~~~"));

}
