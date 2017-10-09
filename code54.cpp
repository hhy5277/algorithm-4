/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/
/*
思路：
在二叉查找树种，寻找两个节点的最低公共祖先。
1、如果a、b都比根节点小，则在左子树中递归查找公共节点。
2、如果a、b都比根节点大，则在右子树中查找公共祖先节点。
3、如果a、b一个比根节点大，一个比根节点小，或者有一个等于根节点，则根节点即为最低公共祖先。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int max = p->val > q->val ? p->val : q->val;
        int min = p->val < q->val ? p->val : q->val;

        if (max < root->val) {
        	return lowestCommonAncestor(root->left, p, q);
        }
        if (min > root->val) {
        	return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
    }
};