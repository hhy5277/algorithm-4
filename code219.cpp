/*
是否可以找到从根节点到某一节点（可以是根节点）的路径和为给定值。
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
/*
水题一道

思路：回溯法
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
    	if (NULL == root) {
    		return false;
    	}

    	int sum = 0;

    	return _hasPathSum(root, target, sum);
    }

    bool _hasPathSum(TreeNode* root, int target, int& sum) {
    	if (NULL == root) {
            return false;
    	}

    	sum += root->val;
    	if (sum == target) {
    		return true;
    	}
    	else if (sum < target) { // 继续搜索
    		return _hasPathSum(root->left, target, sum) || _hasPathSum(root->right, target, sum);
    	}
    	else { // 回溯到上一层之前，需要减去这一层的val值，以恢复到上一层的状态
    		sum -= root->val;

    		return false;
    	}
    }
};