/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int preIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        // Pick current root from preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int index = inorderIndex[rootVal];

        // Build left and right subtrees
        root->left = buildTreeHelper(preorder, left, index - 1);
        root->right = buildTreeHelper(preorder, index + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};