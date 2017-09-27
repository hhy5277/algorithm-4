/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
/*
思路：
递归遍历左子树和右子树，
如果左子树和右子树都相同（是与的关系，而不是或的关系），
那么两棵树相同
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
        	return true;
        }

        if (p == NULL || q == NULL) {
        	return false;
        }

        if (p->val == q->val) {
        	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else {
        	return false;
        }
    }
};