/*
思路：
递归判断每个节点（即这个节点的左节点和右节点同时满足）的左子树和右子树它们的高度差的绝对值是否小于1
如果大于1，则不是平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
        	return true;
        }

        int diff = abs(get_depth(root->left) - get_depth(root->right));

        if (diff > 1) {
        	return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    /*
    作用：计算以这个节点为根节点的树的高度。
    */
    int get_depth(TreeNode* root) {
    	if (root == NULL) {
    		return 0;
    	}

        queue<TreeNode*> q;

        q.push(root);

        int depth = 0;

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
            	if (q.front()->left != NULL) {
            		q.push(q.front()->left);
            	}
            	if (q.front()->right != NULL) {
            		q.push(q.front()->right);
            	}

            	q.pop();
            }

            depth++;
        }

        return depth;
    }
};