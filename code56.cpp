/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;

        if (root == NULL) {
        	return v;
        }

        __binaryTreePaths(root, v, to_string(root->val));

        return v;
    }

    void __binaryTreePaths(TreeNode* root, vector<string> &v, string s) {
        if ((root->left == NULL) && (root->right == NULL)) { // 当这个节点是叶子节点的时候，不要继续搜索了，把路径字符串加入数组中，然后返回。
            v.push_back(s);

        	return ;
        }
        
        if (root->left != NULL) {
            __binaryTreePaths(root->left, v, s + "->" + to_string(root->left->val)); // 既然往左搜索，那么就把左节点连接起来
        }
        if (root->right != NULL) {
            __binaryTreePaths(root->right, v, s + "->" + to_string(root->right->val)); // 既然往右搜索，那么就把右节点连接起来
        }
    }
};