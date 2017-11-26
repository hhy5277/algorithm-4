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
关键是怎么判断是否是左叶子节点
*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (NULL == root) {
        	return 0;
        }
        if (NULL == root->left && NULL == root->right) {
        	return 0;
        }

        int sum = 0;
        __sumOfLeftLeaves(root, sum);

        return sum;
    }

    void __sumOfLeftLeaves(TreeNode* root, int& sum) {
        if (NULL == root) {
        	return ;
        }

        if (root->left != NULL && NULL == root->left->left && NULL == root->left->right) { // 到达左叶子节点的父节点
        	sum += root->left->val;
        }

        __sumOfLeftLeaves(root->left, sum);
        __sumOfLeftLeaves(root->right, sum);
    }
};