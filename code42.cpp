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
首先定义一个函数，用来判断两颗二叉树是否相等。
然后判断一颗二叉树t是否是二叉树s的子树，
仅需依次递归判断二叉树s的左子树和右子树是否与t相等即可。
*/
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) { // s更大
        if (s == NULL) {
        	return false;
        }

        if (isSame(s, t)) {
        	return true;
        }

        return isSubtree(s->left, t) || isSubtree(s->right, t); // 只要s的左子树或者右子树有一个与t相同，那么就可以返回判断是true
    }

    bool isSame(TreeNode* s, TreeNode* t) {
    	if (s == NULL && t == NULL) {
    		return true;
    	}
    	if (s == NULL || t == NULL) {
    		return false;
    	}
    	if (s->val != t->val) {
    		return false;
    	}

    	return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};