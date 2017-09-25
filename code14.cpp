/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/

/*
思路：
题解： 
这题就是说对每个节点，加上所有比它大的值。 
说简单也简单，关键在于二分查找树。 
利用二分查找树的特性，我们可以很容易得出从大到小的数组序列，即中序遍历（右子树-根节点-左子树），如例子中给的就是【13，5，2】。 
那么就很明显了，一次遍历，加上前面的数，如5变为5+13=18， 2变为2+18=20。 
总体复杂度O（n）。
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
    TreeNode* convertBST(TreeNode* root) {
    	int sum = 0;
    	convert(root, sum);

        return root;
    }

    void convert(TreeNode* root, int &sum) {

        if (root == NULL) {
        	return ;
        }

        convert(root->right, sum);
        root->val += sum;
        sum = root->val;
        convert(root->left, sum);
    }
};