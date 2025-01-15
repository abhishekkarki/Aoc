#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

string reorganizeString(string s) {
    // put the string in the unordered_map 
    unordered_map<char, int> freq; 
    for (char ch : s) {
        freq[ch]++;
    }
    
    // putthing into the max heap
    priority_queue<pair<int, char>> maxHeap;
    for (auto [ch, count] : freq) {
        maxHeap.push({count, ch});
    }

    string result;
    pair<int, char> prev = {0, '#'};

    while (!maxHeap.empty()) {
        auto [count, ch] = maxHeap.top();
        maxHeap.pop();
        result += ch;

        if (prev.first > 0) {
            maxHeap.push(prev);
        }

        prev = {count - 1, ch};
    }
    return s.length() == result.length() ? result : "";
}

int main() {
    string s = "aab";
    cout << reorganizeString(s);
}