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
水题一道
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (NULL == root) {
        	return 0;
        }

        return _maxDepth(root);
    }

    int _maxDepth(TreeNode* root) {
    	if (NULL == root) {
    		return 0;
    	}

    	return max(_maxDepth(root->left), _maxDepth(root->right)) + 1;

    }
};