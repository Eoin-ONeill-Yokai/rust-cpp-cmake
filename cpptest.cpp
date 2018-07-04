#include <iostream>
#include <assert.h>
#include "Config.h"
#include "rust_test.h"

int main(int argc, char* argv[]) {
  std::cout << "I'm built! \n";
  std::cout << "Version Number: " << RUSTCPP_VERSION_MAJOR << "." << RUSTCPP_VERSION_MINOR << "...\n";

  int five = 5;
  int six = add_to(five);

  assert( six > five );
  std::cout << six << " is greater than " <<  five << "!!!! \n";

  std::cout << rust_test_random() << " is your random value. \n";
  return 0;
}
