#include <iostream>
#include <cstring>
#include <string>

#include "parameters.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) // No command
    {
        meta::displayUsage();
        return 0; // Finished
    }
    if (std::strcmp(argv[1], "version") == 0) // "calc" command
    {
        std::cout << "math version " << meta::version << "\n";
    }
}