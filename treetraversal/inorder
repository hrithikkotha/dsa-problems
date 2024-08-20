/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, vector<int> &a) {
        if (!root) {
            return;
        }
        traverse(root->left, a);
        a.push_back(root->val);
        traverse(root->right, a);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<vector<int>> f;
        vector<int> a;
        traverse(root, a);
        // int t = 0;

       // sort(a.begin(), a.end());
        return a[k - 1];
    }
};
