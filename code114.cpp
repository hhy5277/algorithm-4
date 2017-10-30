/*
Given a binary tree, 
find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        std::vector<int> v;

        q.push(root);

        while (!q.empty()) {
        	int n = q.size();

        	for (int i = 0; i < n; ++i) {
        		if (i == 0) {
        			v.push_back(q.front()->val);
        		}

        		if (q.front()->left != NULL) {
        			q.push(q.front()->left);
        		}
        		if (q.front()->right != NULL) {
        			q.push(q.front()->right);
        		}

        		q.pop();
        	}
        }

        std::vector<int>::iterator iter = v.end();
        --iter;

        return *iter;
    }
};