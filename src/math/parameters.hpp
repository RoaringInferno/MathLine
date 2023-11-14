#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <iostream>
#include <string>

namespace parameters
{}

namespace meta
{
    /*
     * Version Number
     * Semantic Versioning
     * Major Feature.Feature.Patch
     */
    const std::string version = "a0.0.0";

    void displayUsage()
    {
        std::cout << "usage: math <command>\n"
                  << "\n"
                  << "Program commands:\n"
                  << "\tversion   Displays version information\n";
    }
}

#endif