// Group Anagrams
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // initialize an unordered map
    unordered_map<string, vector<string>> hashMap;

    for (const auto& s : strs) {
        vector<int> count(0, 26);
        
        for (const auto& c : s) {
            count.push_back[c - 'a'];
        }
        int key = to_string(count[0]);

        for (int i = 1; i < 26; ++i) {
            key = ',' + to_string(count[i]);
        }
        hashMap[key].push_back(s);
    }

    vector<vector<string>> result;

    for (const auto& second : hashMap) {
        result.push_back(pair.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
}