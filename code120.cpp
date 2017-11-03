/*
题目描述
输入两棵二叉树A，B，
判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    	bool res = false;

    	if (pRoot1 == NULL || pRoot2 == NULL) { // 别忘了递归的终止条件
    		return false;
    	}

        if (pRoot1->val == pRoot2->val) {
        	res = isTree1HaveTree2(pRoot1, pRoot2);
        }
        if (res == false) {
        	res = HasSubtree(pRoot1->left, pRoot2);
        }
        if (res == false) {
        	res = HasSubtree(pRoot1->right, pRoot2);
        }

        return res;
    }

    bool isTree1HaveTree2(TreeNode* root1, TreeNode* root2) {
        if (root2 == NULL) {
        	return true;
        }
        if (root1 == NULL) {
        	return false;
        }

        if (root1->val != root2->val) {
        	return false;
        }

        return isTree1HaveTree2(root1->left, root2->left) && isTree1HaveTree2(root1->right, root2->right);

    }
};