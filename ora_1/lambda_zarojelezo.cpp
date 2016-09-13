#include <iostream>
#include <functional>

typedef std::function<std::string(std::string)> Dekorator;

void kiir(std::string s, Dekorator  dekorator) {
  std::cout << dekorator(s) << std::endl;
}

std::string zarojelez(std::string str) {
  return "(" + str + ")";
}

Dekorator zarojelezoGenerator(std::string zarojel, std::string zarojel2) {
  //ha = van a []-ban akkor mindent masol ami a korulotte levo scope-ban van.
  return [=](std::string x) {
    return zarojel + x + zarojel2;
  };
}

Dekorator dekoratorGenerator(Dekorator dekorator) {
  return dekorator;
}

//az initializer_list a ... ot helyettesiti 
Dekorator dekoratorGenerator(std::initializer_list<Dekorator> dekors) {
  //ha = van a []-ban akkor mindent masol ami a korulotte levo scope-ban van.
  return [dekors](std::string str) {
    for(auto dekor: dekors) {
      str = dekors(str);
    }
    return str;
  }
}

int main() {
  Dekorator cakkozo = zarojelezoGenerator("{", "}");
  kiir("alma", zarojelezoGenerator("< ", " >"));
  kiir("korte",  zarojelezoGenerator("==== ", " ===="));
  kiir("dinnye",  zarojelezoGenerator("~~~\t", "\t~~~"));
  kiir("barack", dekoratorGenerator(cakkozo,
				    zarojelezoGenerator("==== ", " ===="),
				    zarojelezoGenerator("~~~\t", "\t~~~"));
}
