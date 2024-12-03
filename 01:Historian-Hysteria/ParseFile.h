#ifndef PARSE_FILE_H
#define PARSE_FILE_H

#include <fstream>

struct ParseFile {
    std::ifstream inputFile;
    inputFile.open("./input.txt");

    if (!inputFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        // ignore comment lines
        if (line[0] == '#') {
            continue;
        }

        std::stringstream stream(line);
        std::string chunk;
        
        int left = 0;
        int right = 0;
        // Read two elements from the line
        if (stream >> left >> right) {
            continue;
        } else {
            std::cout << "skipping invalid line: " << line << std::endl;
        }
    }
    inputFile.close();
}
#endf //PARSE_FILE_H