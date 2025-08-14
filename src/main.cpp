#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "temperature/convert.hpp"

int main(int argc, char** argv) {
  std::cout << "Temperature Converter (CLI)\n";
  if (argc != 3) {
    std::cout << "Usage: ./temp_app c2f 100   OR   ./temp_app f2c 212\n";
    return 0;
  }

  std::string mode = argv[1];
  std::istringstream iss(argv[2]);
  double val = 0.0;
  if (!(iss >> val)) { std::cerr << "Invalid number\n"; return 1; }

  std::cout.setf(std::ios::fixed);
  std::cout << std::setprecision(2);

  if (mode == "c2f") {
    std::cout << val << " C = " << temperature::c_to_f(val) << " F\n";
  } else if (mode == "f2c") {
    std::cout << val << " F = " << temperature::f_to_c(val) << " C\n";
  } else {
    std::cerr << "Use c2f or f2c\n";
    return 1;
  }
  return 0;
}
