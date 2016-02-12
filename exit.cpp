#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  srand((int)time(0));

  cout << "int main() {\n"
       << "  return " << rand() % 256 << ";\n"
       << "}\n";

  return 0;
}
