#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc >= 2) { // Ensure at least one argument a program name is provided
        std::string programName{argv[0]};
        int programNameLength{static_cast<int>(programName.size())};
        int checksum{0};

        for (int i = 0; i < programNameLength; ++i) {
            checksum += programName[i];
        }

        // Calc the key using the same logic as before
        int generatedKey = (checksum << (programNameLength & 0x1f)) ^ (programName[0] * 3);

        // Print generated key
        std::cout << "Generated Key: " << generatedKey << std::endl;
    } else {
        std::cout << "Usage: " << argv[0] << " <program name>" << std::endl;
    }

    return 0;
}