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
    int f(TreeNode* root, bool moveLeft) {
        if (root == nullptr) {
            return 0;
        }

        int sum = 0;
        if (root->left == nullptr && root->right == nullptr && moveLeft) {
            sum += root->val;
        }

        sum += f(root->left, true) + f(root->right, false);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return f(root, false);
    }
};