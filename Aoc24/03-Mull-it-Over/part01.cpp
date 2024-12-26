#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please specify the file name " << std::endl;
        std::cout << "e.g. ./obj filename.txt" << std::endl;
        return 1; // Exit early if file name isn't specified
    }

    std::ifstream inputFile;
    inputFile.open(argv[1]);

    if (!inputFile.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return 1; // Exit if file can't be opened
    }

    std::string line;

    // Define a regular expression pattern to match 'mul(a,b)'
    std::regex mulPattern(R"(mul\((\d+),(\d+)\))");

    int count = 0; 

    // Process each line in the file
    while (std::getline(inputFile, line)) {
        // Ignore comment lines
        if (line[0] == '#') {
            continue;
        }

        // Use the regex to find all matches for 'mul(a,b)' in the line
        std::smatch matches;
        while (std::regex_search(line, matches, mulPattern)) {
            // capture the numbers to multiply
            int a = std::stoi(matches[1].str()); // first capture group
            int b = std::stoi(matches[2].str()); // second capture group

            count += a * b;


            // Move past the last match to find more in the same line
            line = matches.suffix().str();
        }
    }

    std::cout << "result is : " << count << std::endl;

    inputFile.close(); // Close the file when done
    return 0;
}
