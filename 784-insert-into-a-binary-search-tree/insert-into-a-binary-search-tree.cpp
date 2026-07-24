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
        if (root == NULL) return new TreeNode(val);
        
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while(cur) {
            prev = cur;
            if (val > cur->val) cur = cur->right;
            else cur = cur->left;
        }
        TreeNode* newNode = new TreeNode(val);
        if (val > prev->val) prev->right = newNode;
        else prev->left = newNode;
        return root;
    }
};