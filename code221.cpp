/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
思路：水题一道
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > vv;
        vector<int> v;

        if (NULL == root) {
        	return vv;
        }

        _pathSum(root, 0, sum, vv, v);

        return vv;
    }

    void _pathSum(TreeNode* root, int sum, int target, vector<vector<int> >& vv, vector<int> v) {
        if (NULL == root) {
            return ;
        }

        v.push_back(root->val);
    	sum += root->val;

    	if (sum == target) {
    		if (NULL == root->left && NULL == root->right) {
    			vv.push_back(v);
    		}
    		else {
                _pathSum(root->left, sum, target, vv, v);
                _pathSum(root->right, sum, target, vv, v);
    		}
    	}
        else {
            _pathSum(root->left, sum, target, vv, v);
            _pathSum(root->right, sum, target, vv, v);
        }

    }
};