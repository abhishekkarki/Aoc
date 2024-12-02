#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

bool isSorted(const std::vector<int>& numbers) {
    // Check if the numbers are sorted in ascending or descending order
    bool ascending = true, descending = true;

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < numbers[i - 1]) {
            ascending = false;
        }
        if (numbers[i] > numbers[i - 1]) {
            descending = false;
        }
    }

    return ascending || descending;
}

bool checkDifferences(const std::vector<int>& numbers) {
    // Check if the difference between consecutive numbers is between 1 and 3 (inclusive)
    for (size_t i = 1; i < numbers.size(); ++i) {
        int diff = std::abs(numbers[i] - numbers[i - 1]);
        if (diff < 1 || diff > 3) {
            return false; // Difference is not in the allowed range
        }
    }
    return true; // All differences are between 1 and 3
}

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
    int validLineCount = 0;  // Counter for lines that satisfy both conditions
    
    while (std::getline(inputFile, line)) {
        // Ignore comment lines
        if (line[0] == '#') {
            continue;
        }

        std::stringstream stream(line);
        std::string chunk;
        std::vector<int> numbers;

        // Read numbers from the line and store them in a vector
        while (stream >> chunk) {
            try {
                numbers.push_back(std::stoi(chunk)); // Convert string to integer
            } catch (const std::invalid_argument&) {
                std::cout << "Skipping invalid number in line: " << chunk << std::endl;
            }
        }

        // Check if the numbers are sorted and if the differences are valid
        if (isSorted(numbers) && checkDifferences(numbers)) {
            validLineCount++;  // Increment the valid line count if both conditions are satisfied
        }
    }

    inputFile.close();

    // Output the count of valid lines
    std::cout << "Number of valid lines: " << validLineCount << std::endl;

    return 0;
}
