// link: https://leetcode.com/problems/increasing-order-search-tree/

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
   
    TreeNode* newTree = nullptr;
    TreeNode* newTreeRoot = nullptr;
    TreeNode* increasingBST(TreeNode* root) {
        
        if(!root) return nullptr;
        
        traverse(root);
        
        return newTreeRoot;
    }
    
    void traverse(TreeNode* root){
        
        if(!root) return;
        
        traverse(root->left);
        
        if(!newTree){
            newTree = root;
            newTreeRoot = newTree;
        }else{
            newTree->right = root;
            newTree->left = nullptr;
            newTree = newTree->right;
        }
             
        traverse(root->right);
    }
};