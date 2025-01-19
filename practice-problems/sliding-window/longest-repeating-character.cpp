#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaximumScore(vector<int>& stockPrices, int k) {
    int left = 0;
    int maxCount = 0;
    int n = stockPrices.size(); 
    int maxFreq = 0;
    unordered_map<int, int> freqMap;

    for (int right = 0; right < n; ++right) {
        // add the element in the map
        freqMap[stockPrices[right]]++;
        maxFreq = max(maxFreq, freqMap[stockPrices[right]]);

        // shrinking window
        while ((right - left + 1) - maxFreq > k) {
            // decrease the frequency of that element
            freqMap[stockPrices[left]]--;
            if (freqMap[stockPrices[left]] == 0) {
                freqMap.erase(stockPrices[left]);
            }
            left++;
        }

        maxCount = max(maxCount, maxFreq);
    }
    return maxCount;
}

int main() {
    vector<int> stockPrices = {7, 5, 7, 7, 1, 1, 7};
    int k = 3;
    cout << findMaximumScore(stockPrices, k) << endl;
}