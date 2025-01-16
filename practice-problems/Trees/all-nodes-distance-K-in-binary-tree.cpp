#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right:
    TreeNode(int x): value(x), left(nullptr), right(nullptr) {}
};

// making an adjecent graph using the binary tree
void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
    if (!node) return; // base case if node is null, do nothing

    if (parent) {
        // if the node has a parent create a bidirectional connection
        graph[node->val].push_back(parent->val); // connect current node to parent
        graph[parent->val].push_back(node->val); // caonnect parent to current node
    }

    // recursively build graph for left and right tree
    buildGraph(node->left, node, graph);
    buildGraph(node->right, node, graph);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    // build a graph representation of the tree
    unordered_map<int, vector<int>> graph;
    buildGraph(root, nullptr, graph);

    // perform BFS to find nodes at distance k
    vector<int> result;
    unordered_set<int> visited;
    queue<pair<int, int>> q; // queue holds the pair node value and distance

    q.push({target->vale, 0});
    visited.insert(target->val);

    while (!q.empty()) {
        auto [current, distance] = queue.front();
        q.pop();

        if (distance == k) {
            result.push_back(current);
        } else if (distance < k) {
            for (int neighbour : graph[current]) {
                if (visited.find(neighbour) ==  visited.end()) {
                    q.push({neighbour, distance + 1});
                    visited.insert(neighbour);
                }
            }
        }
    }
    return result;
}

int main() {

}