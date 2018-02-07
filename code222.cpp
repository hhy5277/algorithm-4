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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > vv;

        if (root == NULL) {
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