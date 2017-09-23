/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
    TreeNode* invertTree(TreeNode* root) {
        if (NULL == root) {
        	return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
        	int n = q.size();
        	for (int i = 0; i < n; i++) {
        		TreeNode* left_node = q.front()->left;
        		TreeNode* right_node = q.front()->right;

        		q.front()->left = right_node;
        		q.front()->right = left_node;

        		if (q.front()->left != NULL) {
        			q.push(q.front()->left);
        		}
        		if (q.front()->right != NULL) {
        			q.push(q.front()->right);
        		}

        		q.pop();
        	}
        }

        return root;
    }
};