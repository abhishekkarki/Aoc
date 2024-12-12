#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

void parseInput(const std::string& filename, std::vector<int>& list) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "unable to open the file " << filename << std::endl;
        exit(1);
    }
    std::string line;
    std::getline(inputFile, line);
    std::stringstream ss(line);
    int value;
    while (ss >> value) {
        list.push_back(value);
    }
 

}

void solver(std::vector<int>& list) {
    std::vector<int> result;
    for (int i =0; i < list.size(); ++i) {
        // length of the input
        int length = std::to_string(list[i]).length();
        std::cout << length << std::endl;
        // 0 case
        if (list[i] == 0) {
            result.push_back(1);
        }
        // for the odd length digits
        if ((list[i] % 2) == 1) {
            result.push_back(list[i] * 2024);
        }

        // for even length digits
        if ((list[i] % 2) == 0) {
            
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "please provide a input file " << std::endl;
        return 1; 
    }
    std::string filename = argv[1];
    std::vector<int> list;
    
    parseInput(filename, list);

    for (const auto& i : list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    solver(list);
}