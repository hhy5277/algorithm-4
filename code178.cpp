/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
思路：
使用中序遍历
*/
class Solution {
public:
    TreeNode *pre;
    bool isValidBST(TreeNode* root) {
        int res = 1;
        pre = NULL; // 中序遍历序列当前节点的前一个节点

        inorder(root, res);
        if (1 == res) {
        	return true;
        }
        else {
        	return false;
        }
    }

    void inorder(TreeNode *root, int &res) {
        if (!root) return ;
        inorder(root->left, res);
        if (NULL == pre) {
            pre = root;
        } else {
            if (root->val <= pre->val) {
            	res = 0;
            	return ;
            }
            pre = root;
        }
        inorder(root->right, res);
    }
};