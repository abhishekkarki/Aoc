/*
* Palindrome Partitioning
* Time: O(n * 2^n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isPalindrome(std::string s) {
    std::string s1 = s;
    std::reverse(s1.begin(), s1.end());
    if (s1 == s) {
        return true;
    }
    return false;
}

void helper(std::string s, std::vector<std::string>& partition, std::vector<std::vector<std::string>>& result) {
    if (s.size() == 0) {
        result.push_back(partition);
        return;
    }
    for (int i = 0; i < s.size(); ++i) {
        std::string part = s.substr(0, i + 1);

        if (isPalindrome(part)) {
            partition.push_back(part);
            helper(s.substr(i + 1), partition, result);
            partition.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partitioningPalindrome(std::string s) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> partition;
    helper(s, partition, result);
    return result;
}

int main() {
    std::string s = "aab";
    auto result = partitioningPalindrome(s);

    for (const auto& i : result) {
        for (const auto& j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}