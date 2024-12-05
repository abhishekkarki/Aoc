#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

// Function to parse input from the file
void parseInput(const string &filename, vector<pair<int, int>> &rules, vector<vector<int>> &updates) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    string line;

    // Read rules section
    while (getline(inputFile, line)) {
        if (line.empty()) break; // Empty line separates rules and updates
        stringstream ss(line);
        int x, y;
        char delim;
        ss >> x >> delim >> y; // Parse rule in format X|Y
        rules.emplace_back(x, y);
    }

    // Debug: Print parsed rules
    cout  << "Parsed Rules:" << endl;
    for (const auto &[x, y] : rules) {
        cout << x << " | " << y << endl;
    }
    cout << endl;

    // Read updates section
    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<int> update;
        int page;
        while (ss >> page) { // Read each page number
            if (ss.peek() == ',') ss.ignore(); // Ignore commas
            update.push_back(page);
        }
        updates.push_back(update);
    }

    inputFile.close();

    // Debug: Print parsed updates
    cout << "Parsed Updates:" << endl;
    for (const auto &update : updates) {
        for (int page : update) {
            cout << page << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if an update is valid based on the relevant rules
bool isUpdateValid(const vector<int> &update, const vector<pair<int, int>> &rules) {
    // Create a map to store the position of each page in the update
    unordered_map<int, int> position;
    for (int i = 0; i < update.size(); ++i) {
        position[update[i]] = i;
    }

    // Check all relevant rules
    for (const auto &[x, y] : rules) {
        if (position.count(x) && position.count(y)) { // Both pages must exist in the update
            if (position[x] >= position[y]) {
                return false; // Rule violated: X is not before Y
            }
        }
    }

    return true; // All rules satisfied
}

// Function to find the middle page of a sorted update
int findMiddlePage(const vector<int> &update) {
    return update[update.size() / 2];  // Middle element in original order
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string filename = argv[1];

    // Variables to store rules and updates
    vector<pair<int, int>> rules;
    vector<vector<int>> updates;

    // Parse input
    parseInput(filename, rules, updates);

    int middleSum = 0; // To store the sum of middle pages from valid updates

    // Process each update
    for (const auto &update : updates) {
        cout << "Processing Update: ";
        for (int page : update) {
            cout << page << " ";
        }
        cout << endl;

        // Filter relevant rules
        vector<pair<int, int>> relevantRules;
        for (const auto &[x, y] : rules) {
            if (find(update.begin(), update.end(), x) != update.end() &&
                find(update.begin(), update.end(), y) != update.end()) {
                relevantRules.emplace_back(x, y);
            }
        }

        // Debug: Print relevant rules for this update
        cout << "Relevant Rules for Update: ";
        for (const auto &[x, y] : relevantRules) {
            cout << "(" << x << " | " << y << ") ";
        }
        cout << endl;

        // Check if the update is valid
        if (isUpdateValid(update, relevantRules)) {
            cout << "Update is VALID" << endl;

            // If valid, find the middle page and add to the sum
            int middlePage = findMiddlePage(update);
            cout << "Middle Page: " << middlePage << endl;
            middleSum += middlePage;
        } else {
            cout << "Update is INVALID" << endl;
        }

        cout << endl;
    }

    // Output the final result
    cout << "The sum of middle pages from valid updates is: " << middleSum << endl;

    return 0;
}