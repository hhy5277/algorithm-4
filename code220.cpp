/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
水题一道
因为不是回溯法，所以不需要给sum引用类型
[5,4,8,11,null,13,4,7,2,null,null,null,1]
22
                      5
                4             8
            11     n      13     4
          7    2         n  n  n   1

*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if (NULL == root) {
            return false;
        }

        int sum = 0;

        return _hasPathSum(root, target, sum);
    }

    bool _hasPathSum(TreeNode* root, int target, int sum) {
        if (NULL == root) {
            return false;
        }
        sum += root->val;
        if (target > 0) {
            if (sum == target) {
                if (root->left == NULL && root->right == NULL) {
                    return true;
                }
                else {
                    return _hasPathSum(root->left, target, sum) || _hasPathSum(root->right, target, sum);
                }
            }
            else {
                return _hasPathSum(root->left, target, sum) || _hasPathSum(root->right, target, sum);
            }
        }
        else {
            if (sum == target) {
                if (root->left == NULL && root->right == NULL) {
                    return true;
                }
                else {
                    return _hasPathSum(root->left, target, sum) || _hasPathSum(root->right, target, sum);
                }
            }
            else {
                return _hasPathSum(root->left, target, sum) || _hasPathSum(root->right, target, sum);
            }
        }
    }
};