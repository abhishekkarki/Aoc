#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <unordered_map>
#include <algorithm>

// Function to parse the file
void parseFile(const std::string& filename, std::vector<std::pair<int, int>>& rules, std::vector<std::vector<int>>& updates) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the input file :( " << filename << std::endl;
        exit(1);
    }
    std::string line;
    // Get the rules into the vector
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            break;
        }
        std::stringstream ss(line);
        int x, y;
        char delim;
        ss >> x >> delim >> y;
        rules.emplace_back(x, y);
    }

    // Read the updates into a vector
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::vector<int> update;
        int page;
        while (ss >> page) {
            if (ss.peek() == ',') ss.ignore();
            update.push_back(page);
        }
        updates.push_back(update);
    }

    inputFile.close();
}

// Function to check if an update is valid
bool isUpdateValid(const std::vector<int>& update, const std::vector<std::pair<int, int>>& rules) {
    std::unordered_map<int, int> position;
    for (int i = 0; i < update.size(); ++i) {
        position[update[i]] = i;
    }
    for (const auto& [x, y] : rules) {
        if (position.count(x) && position.count(y)) {
            if (position[x] >= position[y]) {
                return false; // Rule violation
            }
        }
    }
    return true; // All rules satisfied
}

// Function to find the middle page of a sorted update
int findMiddlePage(const std::vector<int>& update) {
    return update[update.size() / 2];
}

// Function to fix the update
int fixer(std::vector<int> update, const std::vector<std::pair<int, int>>& rules) {
    std::unordered_map<int, int> position;
    for (int i = 0; i < update.size(); ++i) {
        position[update[i]] = i;
    }

    bool changed;
    do {
        changed = false;
        for (const auto& [x, y] : rules) {
            if (position.count(x) && position.count(y) && position[x] >= position[y]) {
                // Swap elements to satisfy the rule
                std::swap(update[position[x]], update[position[y]]);
                std::swap(position[x], position[y]);
                changed = true; // Mark as changed for another iteration
            }
        }
    } while (changed);

    // Debugging output
    std::cout << "Fixed update: ";
    for (const auto& page : update) {
        std::cout << page << " ";
    }
    std::cout << std::endl;

    return findMiddlePage(update);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide the input.txt file in the command argument" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<std::pair<int, int>> rules;
    std::vector<std::vector<int>> updates;

    parseFile(filename, rules, updates);
    int totalSum = 0;

    for (const auto& update : updates) {
        std::vector<std::pair<int, int>> relevantRules;

        // Find relevant rules for the current update
        for (const auto& [x, y] : rules) {
            if (std::find(update.begin(), update.end(), x) != update.end() &&
                std::find(update.begin(), update.end(), y) != update.end()) {
                relevantRules.emplace_back(x, y);
            }
        }

        // Validate or fix the update
        if (!isUpdateValid(update, relevantRules)) {
            totalSum += fixer(update, relevantRules);
        }
    }

    std::cout << "The total sum is: " << totalSum << std::endl;

    return 0;
}