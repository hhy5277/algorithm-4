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
    string tree2str(TreeNode* t) {
        string s;

        if (NULL == t) {
        	return "";
        }

        s += to_string(t->val);
        if (t->left != NULL) {
        	s += "(" + tree2str(t->left) + ")";
        }

        if (t->left == NULL && t->right != NULL) { // 这一步是细节
        	s += "()";
        }

        if (t->right != NULL) {
        	s += "(" + tree2str(t->right) + ")";
        }

        return s;
    }
};