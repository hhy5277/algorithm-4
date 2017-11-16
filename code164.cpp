/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        if (NULL == root) {
        	return 0;
        }

        int res = 0, temp = 0;
        __sumNumbers(root, res, temp);

        return res;
    }

    void __sumNumbers(TreeNode* root, int& sum, int temp) {
        temp = temp * 10 + root->val;

        if (root->left != NULL) {
        	__sumNumbers(root->left, sum, temp);
        }
        if (root->right != NULL) {
            __sumNumbers(root->right, sum, temp);
        }

        if (NULL == root->left && NULL == root->right) {
        	sum += temp;
        }
    }
};