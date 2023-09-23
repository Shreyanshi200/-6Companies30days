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
      int height(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right)+1;
        return ans;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int left=height(root->left);
        int right=height(root->right);
        
         if(left>right){
           return subtreeWithAllDeepest(root->left);
        }
        else if(left<right){
            return subtreeWithAllDeepest(root->right);
        }
        else return root;
    }
};