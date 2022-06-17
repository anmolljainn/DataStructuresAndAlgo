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
    int helper(TreeNode* &root,int &cameras){
        if(root==NULL){
            return 1;
        }
        int lchild = helper(root->left,cameras);
        int rchild = helper(root->right,cameras);
        
        if(lchild==-1 || rchild==-1){
            cameras++;
            return 0;
        }
        if(lchild==0 || rchild==0) return 1;
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if(helper(root,cameras)==-1){
            cameras++;
        }
        return cameras;
    }
};