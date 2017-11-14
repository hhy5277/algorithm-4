/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
    	std::vector<int> v;
        if (NULL == root) {
            return v;
        }

        stack<TreeNode*> stk;
        stk.push(root);

        TreeNode* temp = NULL;

        while (!stk.empty()) {
        	temp = stk.top();
            v.push_back(temp->val);
            stk.pop();

            if (temp->right != NULL) {
            	stk.push(temp->right);
            }
            if (temp->left != NULL) {
                stk.push(temp->left);
            }
        }

        return v;
    }
};