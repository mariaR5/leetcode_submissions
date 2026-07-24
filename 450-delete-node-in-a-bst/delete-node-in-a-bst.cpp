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
    TreeNode* getLastRight(TreeNode* root) {
        while (root) {
            if (root->right) root = root->right;
            else return root;
        }
        return root;
    }

    TreeNode* getChild(TreeNode* node) {
        if (!node->left) return node->right;
        if (!node->right) return node->left;

        TreeNode* lastRight = getLastRight(node->left);
        lastRight->right = node->right;
        return node->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) return getChild(root);

        TreeNode* cur = root;
        while (cur) {
            if (key < cur->val) {
                if (cur->left && cur->left->val == key) {
                    cur->left = getChild(cur->left);
                    break;
                }
                cur = cur->left;
            }
            else {
                if (cur->right && cur->right->val == key) {
                    cur->right = getChild(cur->right);
                    break;
                }
                cur = cur->right;
            }
        }

        return root;
    }
};