/*
Given a Binary Search Tree and a target number, 
return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9
Output: True

Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28
Output: False
*/

/*
思路：
先对二叉搜索树进行中序遍历，得到从小到大的一个数组。
然后对这个数组的头尾开始，进行相加。直到等于target，返回true；否则返回false
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        middle(root, v);

        int n = v.size();

        for (int i = 0, j = n - 1; i < j;) {
            if (v[i] + v[j] == k) {
            	return true;
            }        	
            else if (v[i] + v[j] < k) {
            	i++;
            }
            else {
            	j--;
            }
        }

        return false;
    }

    void middle(TreeNode* root, vector<int> &a) {
    	if (root == NULL) {
    		return ;
    	}
    	middle(root->left, a);
    	a.push_back(root->val);
    	middle(root->right, a);
    }
};