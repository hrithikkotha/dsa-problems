

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
    void traverse(TreeNode* root,vector<int> &k,int i){
        
        if(!root){
            return;
        }

        if(i==k.size()){
            k.push_back(root->val);
        }
        else{
            k[i]=root->val;
        }

        traverse(root->left,k,i+1);
        traverse(root->right,k,i+1);
        

    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> k;
        traverse(root,k,0);
        return k;
    }
};
