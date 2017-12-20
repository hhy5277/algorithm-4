/*
给定一棵二叉树，返回整棵树的倾斜度。

树节点的倾斜被定义为所有左子树节点值的总和与所有右子树节点值的总和之间的绝对差值。 空节点具有倾斜0。

整棵树的倾斜度定义为所有节点倾斜的总和。

Example:
Input: 
         1
       /   \
      2     3
Output: 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
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
思路：
用层次遍历去遍历每一个节点
然后分别去遍历该节点的左子树和右子树，计算它们倾斜度的差值
*/
class Solution {
public:
    int findTilt(TreeNode* root) {
    	if (NULL == root) {
    		return 0;
    	}

    	return __findTilt(root);
    }

    int __findTilt(TreeNode* root) {
    	queue<TreeNode*> q;
    	q.push(root);
    	int sum = 0;

    	while (!q.empty()) {
    		int left_sum = caculateTheTilt(q.front()->left, 0);
    		int right_sum = caculateTheTilt(q.front()->right, 0);
    		sum += abs(left_sum - right_sum);

            if (NULL != q.front()->left) {
            	q.push(q.front()->left);
            }
            if (NULL != q.front()->right) {
            	q.push(q.front()->right);
            }

            q.pop();
    	}

    	return sum;
    }

    int caculateTheTilt(TreeNode* root, int sum) {
    	if (NULL == root) {
    		return sum;
    	}

    	sum += root->val;
    	sum = caculateTheTilt(root->left, sum);
    	sum = caculateTheTilt(root->right, sum);

    	return sum;
    }
};