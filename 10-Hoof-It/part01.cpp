#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <set>

void parseInput(const std::string& filename, std::vector<std::string>& map) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file " << filename << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(inputFile, line)) {
       map.push_back(line); 
    }

    inputFile.close();

}

std::set<std::vector<int>> try_pos(std::vector<std::string> &map, int x, int y, int prev_val=-1) {
    std::set<std::vector<int>> visited_posns;
    if (!(0 <= x && x < map.size()) || !(0 <= y && y < map[0].size()))
        return {{-1, -1}};
    if (map[x][y]-48 != prev_val + 1)
        return {{-1, -1}};
    if (prev_val == 8)
        return {{x, y}};
    std::set<std::vector<int>> temp;
    temp = try_pos(map, x+1, y, prev_val + 1);
    visited_posns.insert(temp.begin(), temp.end());
    temp = try_pos(map, x-1, y, prev_val + 1);
    visited_posns.insert(temp.begin(), temp.end());
    temp = try_pos(map, x, y+1, prev_val + 1);
    visited_posns.insert(temp.begin(), temp.end());
    temp = try_pos(map, x, y-1, prev_val + 1);
    visited_posns.insert(temp.begin(), temp.end());

    return visited_posns;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "please provide the input file " << std::endl;
        return 1; 
    }
    std::string filename = argv[1];
    // defining a vector of vector
    std::vector<std::string> map;
    parseInput(filename, map);

    // for debugging printing the vector
    for (const auto& row : map) {
        std::cout << row << " ";
    }
    std::cout << std::endl;

   int p1 = 0;
    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[i].size(); j++) {
            if (map[i][j] == '0')
                p1 += try_pos(map, i, j).size() - 1;
        }
    }
    std::cout << "p1: " << p1 << '\n';

} 
