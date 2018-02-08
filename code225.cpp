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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > vv;
        vector<int> v;
        queue<TreeNode*> q;

        if (NULL == root) {
        	return vv;
        }

        q.push(root);
        while (!q.empty()) {
        	v.clear();
        	int n = q.size();

        	for (int i = 0; i < n; ++i) {
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

        return vv;
    }
};