#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]); // Build the graph
        }

        vector<int> state(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        stack<int> topologicalOrder;

        function<bool(int)> dfs = [&](int course) {
            if (state[course] == 1) return false; // Cycle detected
            if (state[course] == 2) return true;  // Already processed

            state[course] = 1; // Mark as visiting

            for (int neighbor : graph[course]) {
                if (!dfs(neighbor)) return false; // Cycle detected
            }

            state[course] = 2; // Mark as visited
            topologicalOrder.push(course); // Push to topological order
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0 && !dfs(i)) {
                return false; // Cycle detected
            }
        }

        return true; // All courses can be completed
    }
};

int main() {
    Solution solution;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    cout << "Can finish courses: " << (solution.canFinish(2, prerequisites) ? "Yes" : "No") << endl;
    return 0;
}