/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

Note: There are at least two nodes in this BST.
*/
/*
思路：先用中序遍历把节点的值按从小到大的顺序保存在数组里面，然后再计算数组相邻两个值之间的最小值
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
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> v;

        middle(root, v);

        int min_diff = abs(v[0] - v[1]);
        int node_nums = v.size();

        for (int i = 1; i < node_nums - 1; i++) {
        	if (min_diff > abs(v[i] - v[i + 1])) {
                min_diff = abs(v[i] - v[i + 1]);
        	}
        }

        return min_diff;
    }

    void middle(TreeNode* root, std::vector<int> &v) {
    	if (root == NULL) {
    		return;
    	}

        middle(root->left, v);
    	v.push_back(root->val);
        middle(root->right, v);
    }
};