#include <iostream>
#include <vector>

using namespace std;

int maximumUnits(vector<vector<int, int>>& boxTypes, int truckSize) {
    // sort the 2D vector based on the second index of the element
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    });

    int result = 0;
    for (const auto& box : boxTypes) {
        int boxCount = min(truckSize, box[0]);
        result += box[1] * boxCount;
        truckSize -= boxCount;

        if (truckSize == 0) {
            break;
        }
    }
    return result;
}

int main() {
    vector<vector<int, int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;
    maximumUnits(boxTypes, truckSize);
}