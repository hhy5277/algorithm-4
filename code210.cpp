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
Given a binary tree, find the length of the longest path where each node in the path has the same value. 
This path may or may not pass through the root.
*/
/*
思路：使用广度优先遍历遍历每一个节点。
对每一个节点使用深度优先遍历，找出子树相同元素的个数。
然后比较每一个节点。找出最大值即可。
*/
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (NULL == root) {
        	return 0;
        }

        return __longestUnivaluePath(root);
    }

    int __longestUnivaluePath(TreeNode* root) {
    	queue<TreeNode*> q;
    	q.push(root);
    	int max_path = 0;

    	while (!q.empty()) {
    		if (q.front()->left != NULL) {
    			q.push(q.front()->left);
    		}
    		if (q.front()->right != NULL) {
    			q.push(q.front()->right);
    		}

    		max_path = max(max_path, theUnivaluePath(q.front(), q.front()->val, 0));
    		q.pop();
    	}

    	return max_path;
    }

    int theUnivaluePath(TreeNode* root, int target, int num) {
        if (root->left != NULL && target == root->left->val) {
        	num = theUnivaluePath(root->left, target, num + 1);
        }
        if (root->right != NULL && target == root->right->val) {
        	num = theUnivaluePath(root->right, target, num + 1);
        }


        return num;
    }
};