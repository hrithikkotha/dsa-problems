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
    set<int> s;
    void preorder(TreeNode* root, vector<int>& an, bool& ans) {

        if (!root) {
            return;
        }

        if (root->left != NULL && root->right != NULL) {
            if (root->left->val >= root->right->val) {
                ans = false;
            }
        }
        if (root->left != NULL) {
            if (root->left->val >= root->val) {
                ans = false;
            }
        }
        if (root->right != NULL) {
            if (root->right->val <= root->val) {
                ans = false;
            }
        }

        preorder(root->left, an, ans);
        an.push_back(root->val);
        s.insert(root->val);
        preorder(root->right, an, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans, check;
        bool an = true;
        preorder(root, ans, an);
        check = ans;
        sort(check.begin(), check.end());
        if (s.size() != ans.size()) {
            return false;
        }
        if (check == ans && an) {
            return true;
        } else {
            return false;
        }
    }
};
