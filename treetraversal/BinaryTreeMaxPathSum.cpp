class Solution {
public:
int ans=INT_MIN;
    int find(TreeNode* temp,int &ans){
        if(!temp) return 0;

        int left=max(find(temp->left,ans),0);
        int right=max(find(temp->right,ans),0);
        ans=max(ans,temp->val+left+right);
        return max(temp->val+left,temp->val+right);
    }
    int maxPathSum(TreeNode* root) {
        find(root,ans);
        return ans;
    }
};
