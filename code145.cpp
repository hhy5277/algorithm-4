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
    int TreeDepth(TreeNode* pRoot) {
        if (NULL == pRoot) {
        	return 0;
        }

        return __TreeDepth(pRoot);
    }

    int __TreeDepth(TreeNode* root) {
    	if (NULL == root) {
    		return 0;
    	}

    	int left = __TreeDepth(root->left);
    	int right = __TreeDepth(root->right);

    	return left > right ? left + 1 : right + 1;
    }
};