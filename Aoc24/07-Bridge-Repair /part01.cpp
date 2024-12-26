#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>

// Recursive helper function to check if we can achieve the target using `+` and `*`
bool canFormTarget(const std::vector<long long>& nums, int currentIndex, long long currentValue, long long target) {
    if (currentIndex == (int)nums.size() - 1) {
        return (currentValue == target);
    }

    if (canFormTarget(nums, currentIndex + 1, currentValue + nums[currentIndex + 1], target)) {
        return true;
    }

    if (canFormTarget(nums, currentIndex + 1, currentValue * nums[currentIndex + 1], target)) {
        return true;
    }

    return false;
}

// Function to check if the target can be formed
bool checkTarget(const std::vector<long long>& vec) {
    if (vec.size() < 2) {
        return false;
    }

    long long target = vec[0];
    std::vector<long long> nums(vec.begin() + 1, vec.end());

    if (nums.size() == 1) {
        return (nums[0] == target);
    }

    return canFormTarget(nums, 0, nums[0], target);
}

bool isInteger(const std::string &s) {
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '-' || s[0] == '+') {
        if (s.size() == 1) return false;
        start = 1;
    }
    for (size_t i = start; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    return true;
}

void parseInput(const std::string& filename, std::vector<std::vector<long long>>& data) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Cannot open the given file: " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        std::vector<long long> row;
        std::stringstream ss(line);
        std::string targetStr;

        if (!std::getline(ss, targetStr, ':')) {
            std::cerr << "Warning: Skipping malformed line: " << line << std::endl;
            continue;
        }

        if (!isInteger(targetStr)) {
            std::cerr << "Warning: Target is not an integer on line: " << line << std::endl;
            continue;
        }

        try {
            long long targetVal = std::stoll(targetStr);
            row.push_back(targetVal);
        } catch (const std::exception &e) {
            std::cerr << "Warning: Failed to convert target to integer: " << targetStr << " on line: " << line << std::endl;
            continue;
        }

        std::string temp;
        while (ss >> temp) {
            if (!isInteger(temp)) {
                std::cerr << "Warning: Non-integer token '" << temp << "' on line: " << line << std::endl;
                continue;
            }
            try {
                long long val = std::stoll(temp);
                row.push_back(val);
            } catch (const std::exception &e) {
                std::cerr << "Warning: Failed to convert '" << temp << "' to integer on line: " << line << std::endl;
                continue;
            }
        }

        if (!row.empty()) {
            data.push_back(row);
        }
    }

    inputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide the input.txt file" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<std::vector<long long>> data;
    long long sum = 0;

    parseInput(filename, data);

    std::cout << "Parsed Data:" << std::endl;
    for (const auto& row : data) {
        for (const auto& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    for (const auto &row : data) {
        if (!row.empty()) {
            long long target = row[0];
            if (checkTarget(row)) {
                sum += target;
            }
        }
    }

    std::cout << "Sum of all satisfiable targets: " << sum << std::endl;
    return 0;
}