// Group Anagrams
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hashMap;
    vector<vector<string>> result;

    for (auto& str : strs) {
        vector<int> count(26, 0);

        for (auto& ch : str) {
            count[ch - 'a']++;
        }

        stringstream keyStream;
        for (int i = 0; i < 26; ++i) {
            keyStream << count[i] << ",";
        }
        string key = keyStream.str();

        // add the original string in the hashmap under the computed key
        hashMap[key].push_back(str);
    }
    // collect the results from the hashmap
    for (auto& item : hashMap) {
        result.push_back(item.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}