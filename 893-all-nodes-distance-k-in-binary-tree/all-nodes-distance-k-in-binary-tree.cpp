/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root, TreeNode* parent,
                    unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (!root) return;

        if (parent) {
            graph[root].push_back(parent);
            graph[parent].push_back(root);
        }

        buildGraph(root->left, root, graph);
        buildGraph(root->right, root, graph);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        buildGraph(root, nullptr, graph);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            if (dist == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                for (auto neigh : graph[node]) {
                    if (!visited.count(neigh)) {
                        visited.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
            dist++;
        }

        return {};
    }
};