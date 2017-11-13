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
    int minDepth(TreeNode* root) {
    	if (NULL == root) {
    		return 0;
    	}
    	if (NULL == root->left && NULL == root->right) {
    		return 1;
    	}
    	// 上面的两个if是用来结束递归的
        
        if (NULL == root->left) {
        	return 1 + minDepth(root->right);
        }
        else if (NULL == root->right) {
        	return 1 + minDepth(root->left);
        }
        else {
        	return 1 + min(minDepth(root->left), minDepth(root->right));
        }
    }
};