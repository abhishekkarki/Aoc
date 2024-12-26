/*
* Find Missing And Repeated Values
* Using Unordered Sets 
* Time: O(n^2)
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> uset;
        vector<int> ans;
        int a = 0, b = 0;
        int n = grid.size();
        int aspectedSum = (n*n) * (n*n + 1) / 2;
        cout << "The value of sum " << aspectedSum << endl;
        int actualSum = 0; 

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                actualSum += grid[i][j];
                if (uset.find(grid[i][j]) != uset.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                uset.insert(grid[i][j]);
            }
        }
        b = aspectedSum - (actualSum - a);
        ans.push_back(b);
        return ans;
    }
};