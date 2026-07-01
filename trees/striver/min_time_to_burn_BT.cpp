Problem Statement: Given a target node data and a root of binary tree. 
If the target is set on fire, determine the shortest amount of time needed to burn the entire binary tree. 
It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

Input : root = [1, 2, 3, 4, null, 5, 6, null, 7]. target = 1
Output : 3
Explanation :The node with value 1 is set on fire.
In 1st second it burns node 2 and node 3.
In 2nd second it burns nodes 4, 5, 6.
In 3rd second it burns node 7.

Approach:
Method 1: Do similar to "all nodes k dist away problem.

Method 2: 
      1. Convert Binary Tree to Graph: Use DFS or BFS to traverse the tree. For each node:
                Create a bi-directional edge between the node and its left child (if exists).
                Create a bi-directional edge between the node and its right child (if exists).
                Store these edges in an adjacency list format.
      2. Initialize BFS: Create a queue and a visited set.
                Push the target node’s value into the queue.
                Mark it as visited.
                Initialize a time counter to 0.
      3. Perform BFS Level-by-Level: While the queue is not empty:
                Get the current level size (number of nodes burning at this second).
                For each node at this level:
                    Explore all its neighbors (from the graph).
                    If a neighbor is not visited:  Mark it visited and add it to the queue.
                    Increment the time counter after each level.
      4. Return time Once all nodes are burned( when queue gets empty).

  
#include <bits/stdc++.h>
using namespace std;

// Definition of the binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to calculate minimum time to burn the entire tree from the target node
    int minTime(TreeNode* root, int target) {
        // Create an undirected graph using adjacency list
        unordered_map<int, vector<int>> graph;
        buildGraph(root, nullptr, graph);

        // Use a set to track visited (burned) nodes
        unordered_set<int> visited;

        // Use queue for BFS starting from the target node
        queue<int> q;
        q.push(target);
        visited.insert(target);

        // Track time taken to burn the tree
        int time = 0;

        // Perform level-order BFS to simulate the spread of fire
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            // Process each node at the current level
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                // Traverse all adjacent (connected) nodes
                for (int neighbor : graph[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                        burned = true;
                    }
                }
            }

            // If fire spread to new nodes, increment time
            if (burned) time++;
        }

        // Return total time taken to burn the tree
        return time;
    }

private:
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& graph) {
        // Base case: if node is null, return
        if (!node) return;

        // If parent exists, connect parent and node bidirectionally
        if (parent) {
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        // Recursively connect left and right children
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }
};
