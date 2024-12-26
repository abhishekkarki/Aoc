#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <algorithm>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please specify the file name" << std::endl;
        std::cerr << "e.g., ./obj filename.txt" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    // Read the entire file content
    std::string input((std::istreambuf_iterator<char>(inputFile)),
                      std::istreambuf_iterator<char>());
    inputFile.close();

    // Normalize spaces: replace multiple spaces/tabs with a single space
    input = std::regex_replace(input, std::regex("\\s+"), " ");

    // Define a flexible regex for instructions
    std::regex instructionPattern(R"(mul\s*\(\s*(\d+)\s*,\s*(\d+)\s*\)|do\s*\(\s*\)|don't\s*\(\s*\))");

    std::smatch match;
    bool enableMul = true; // Initially, `mul` instructions are enabled
    long long result = 0;

    // Process all instructions in the input
    std::string::const_iterator searchStart(input.cbegin());
    while (std::regex_search(searchStart, input.cend(), match, instructionPattern)) {
        std::string matched = match.str();

        if (std::regex_match(matched, std::regex(R"(do\s*\(\s*\))"))) {
            // Enable `mul` processing
            enableMul = true;
        } else if (std::regex_match(matched, std::regex(R"(don't\s*\(\s*\))"))) {
            // Disable `mul` processing
            enableMul = false;
        } else {
            // Process `mul(a,b)` if enabled
            if (enableMul) {
                int a = std::stoi(match[1].str());
                int b = std::stoi(match[2].str());
                result += a * b;
            }
        }

        // Update search position
        searchStart = match.suffix().first;
    }

    std::cout << "The result is: " << result << std::endl;

    return 0;
}