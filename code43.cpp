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
先从上到下进行层次遍历，然后再反转这个二维数组
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > vv;

        if (root == NULL) { // 注意为空的时候，是返回一个二维数组，但是这个二维数组是空的。所以直接返回vv
        	return vv;
        }

        q.push(root);

        while (!q.empty()) { // 整棵树的元素
        	vector<int> v;
        	int n = q.size();

        	for (int i = 0; i < n; i++) { // 一层的元素
        		if (q.front()->left != NULL) {
        			q.push(q.front()->left);
        		}
        		if (q.front()->right != NULL) {
        			q.push(q.front()->right);
        		}

        		v.push_back(q.front()->val);
        		q.pop();
        	}
        	vv.push_back(v);
        }

        reverse(vv.begin(), vv.end());

        return vv;
    }
};