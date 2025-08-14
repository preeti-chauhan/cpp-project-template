// test/run_tests.cpp
// Test program. CTest runs this and checks the exit code (0 = pass).

#include <cmath>
#include <iostream>
#include "temperature/convert.hpp"

// Compare two doubles with a small tolerance.
// Return 0 on pass, 1 on fail.
int check(const char* name, double got, double expect, double eps = 1e-9) {
  if (std::fabs(got - expect) > eps) {
    std::cerr << "[FAIL] " << name << " expected " << expect << " got " << got << "\n";
    return 1;
  }
  std::cout << "[OK] " << name << "\n";
  return 0;
}

int main() {
  int fail = 0;

  // Basic reference points
  fail += check("c_to_f(0) -> 32",    temperature::c_to_f(0),    32);
  fail += check("c_to_f(100) -> 212", temperature::c_to_f(100), 212);
  fail += check("f_to_c(32) -> 0",    temperature::f_to_c(32),    0);
  fail += check("f_to_c(212) -> 100", temperature::f_to_c(212), 100);

  return fail ? 1 : 0;
}
