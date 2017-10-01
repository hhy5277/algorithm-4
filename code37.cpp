/*
Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/
/*
思路：
每次找到数组的中间位置，这个便是BST的 根节点。
根节点的左边区域的中间节点便是左孩子，
根节点的右边区域的中间节点便是右孩子。
如此递归求解
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	int left = 0;
    	int right = nums.size() - 1;
        return __sortedArrayToBST(nums, left, right);
    }

    TreeNode* __sortedArrayToBST(vector<int>& nums, int left, int right) {
    	if (left > right) {
    		return NULL;
    	}

    	int mid = (left + right) / 2;
    	TreeNode* root = new TreeNode(nums[mid]);
    	root->left = __sortedArrayToBST(nums, left, mid - 1);
    	root->right = __sortedArrayToBST(nums, mid + 1, right);

    	return root;
    }
};