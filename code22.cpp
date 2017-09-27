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
    int minDepth(TreeNode *root) {
        if (NULL == root) {
        	return 0;
        }

        int depth = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
        	int n = q.size();

        	for (int i = 0; i < n; i++) {
        		if (q.front()->left == NULL &&q.front()->right == NULL) {
        			return depth;
        		}
        		else {
        			if (q.front()->left != NULL) {
        				q.push(q.front()->left);
        			}
        			if (q.front()->right != NULL) {
        				q.push(q.front()->right);
        			}
        			q.pop();
        		}
        	}
            
            depth++;
        }
    }
};