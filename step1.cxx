#include <iostream>
#include <cstring> 
#include <string>

int main(int argc, char* argv[]) {
  if (argc == 3) { // Use argc for the number of command-line arg
    std::string programName{argv[0]};
    auto firstChar{*(argv[1])};
    auto programNameLength{programName.size()};
    auto expectedKey{std::atoi(argv[2])};
    auto checksum{0};
    auto index{0};
    auto secondArg{argv[1]};

    while (true) {
      checksum += secondArg[index++];
      if (index >= static_cast<int>(strlen(secondArg))) { // Use strlen to get the len
        break;
      }
    }

    if ((checksum ^ firstChar * 3) << (programNameLength & 0x1f) == expectedKey) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  } else {
    std::cout << "Invalid number of arguments. Usage: " << argv[0] << " <program name> <expected key>" << std::endl;
  }

  return 0;
}