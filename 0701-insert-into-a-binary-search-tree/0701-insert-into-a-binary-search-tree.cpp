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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode* x=new TreeNode(val);
            return x;
        }
        if(root->left!=nullptr && val < root->val){
            TreeNode* y= insertIntoBST(root->left,val);
        }
        if(root->right!=nullptr && val > root->val){
            TreeNode* y= insertIntoBST(root->right,val);
        }

        if(root->left==nullptr && val < root->val){
            TreeNode* x=new TreeNode(val);
            root->left=x;
        }
        if(root->right==nullptr && val > root->val){
            TreeNode* x=new TreeNode(val);
            root->right=x;
        }
        return root;
    }
};