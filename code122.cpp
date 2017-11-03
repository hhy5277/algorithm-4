/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，
如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        return __isSymmetrical(pRoot, pRoot);
    }

    bool __isSymmetrical(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
        	return true;
        }

        if (root1 == NULL || root2 == NULL) {
        	return false;
        }

        if (root1->val != root2->val) {
        	return false;
        }

        /*
        注意这里不能写成：
        if (root1->val == root2->val) {
        	return true;
        }
        因为，子树可能不是对称的，所以，前面的递归过程中，
        只能去判断子树不对称。而不能判断子树对称，只能在递归结束后，才能判断树对称
        */

        return __isSymmetrical(root1->left, root2->right) && __isSymmetrical(root1->right, root2->left);
    }
};