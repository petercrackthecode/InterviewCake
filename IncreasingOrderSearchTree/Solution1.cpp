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
    void inorderNodesToQueue(TreeNode * root, queue<TreeNode *> &nodes) {
        if (!root) return;
        
        if (root->left)
            inorderNodesToQueue(root->left, nodes);
        
        nodes.push(root);
        
        if (root->right)
            inorderNodesToQueue(root->right, nodes);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        queue<TreeNode *> nodes;
        
        inorderNodesToQueue(root, nodes);
        
        TreeNode * ans = nullptr,
                 * temp = nullptr;
        TreeNode * dequeuedItem = nullptr;
        
        while (!nodes.empty()) {
            dequeuedItem = nodes.front();
            nodes.pop();
            
            if (!ans) {
                ans = new TreeNode(dequeuedItem->val);
                temp = ans;
            }
            else {
                temp->right = new TreeNode(dequeuedItem->val);
                temp = temp->right;
            }
        }
        
        return ans;
    }
};