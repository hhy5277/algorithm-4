/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    1
 2
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (NULL == root) {
        	return true;
        }

        return _isBalanced(root);
    }

    bool _isBalanced(TreeNode* root) {
        if (NULL == root ) {
        	return true;
        }

        if (abs(depth(root->left) - depth(root->right)) > 1) {
        	return false;
        }

        return _isBalanced(root->left) && _isBalanced(root->right);

    }

    int depth(TreeNode* root) {
    	if (NULL == root) {
    		return 0;
    	}

        queue<TreeNode*> q;
        q.push(root);

        int dep = 0;

        while (!q.empty()) {
        	int n = q.size();

        	for (int i = 0; i < n; ++i) {
        		if (q.front()->left != NULL) {
        			q.push(q.front()->left);
        		}
        		if (q.front()->right != NULL) {
        			q.push(q.front()->right);
        		}

        		q.pop();
        	}

        	++dep;
        }

        return dep;
    }
};