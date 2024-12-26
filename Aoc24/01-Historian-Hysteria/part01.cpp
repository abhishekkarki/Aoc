#include <iostream>
#include <fstream> // standard I/O stream
#include <string>  // std::string
#include <sstream> // sstream
#include <vector>  // std::vector
#include <algorithm>  // std::sort

int main (int argc, char* argv[]) {
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
    
    std::vector<int> rightList;
    std::vector<int> leftList;

    std::string line;
    
    while (std::getline(inputFile, line)) {
        // Ignore comment lines
        if (line[0] == '#') {
            continue;
        }

        std::stringstream stream(line);
        std::string chunk;
        int left = 0;
        int right = 0;
        
        // Read two elements from the line
        if (stream >> left >> right) {
            // Store the pair in the vector
            leftList.push_back(left);
            rightList.push_back(right);
        } else {
            std::cout << "Skipping invalid line: " << line << std::endl;
        }
    }

    inputFile.close();

    // sorting both vectors
    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    int totalDistance = 0;
    for (int i = 0; i < leftList.size(); ++i) {
        totalDistance += abs(leftList[i] - rightList[i]);
    }

    std::cout << totalDistance << std::endl;


    return 0;
}
