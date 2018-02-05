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
    3       2
5     3          9
思路：
给每个节点一个索引，左孩子的索引是 父亲索引 * 2 + 1， 
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;

        q.push(make_pair(root, 0));
        int width = 1;

        while (!q.empty()) {
        	int n = q.size();
        	int l = q.front().second;
        	int r = l;

        	for (int i = 0; i < n; ++i) {
        		TreeNode* node = q.front().first;
        		r = q.front().second;
        		if (node->left != NULL) {
        			q.push(make_pair(node->left, r * 2 + 1));
        		}
        		if (node->right != NULL) {
        			q.push(make_pair(node->right, r * 2 + 2));
        		}

        		q.pop();
        	}

        	width = max(r - l + 1, width);
        }
        
        return width;
    }
};