#include <vector>
#include <iostream>
#include <queue>


using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap to store the K closest points
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];

            // calculating the square distance from the origin
            int distance = (x * x) + (y * y);

            // push the point and it's distance to the max heap
            maxHeap.push({distance, point});

            // if the heap exceed the size K, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract the K closest points from heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
}

int main() {
    vector<vector<int>> list = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> result;
    result = kClosest(list, k);
    
    for (const auto& i : result) {
        for (const auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}