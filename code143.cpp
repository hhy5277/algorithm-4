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
    TreeNode* KthNode(TreeNode* pRoot, int k) {
    	if (NULL == pRoot) {
    		return NULL;
    	}

    	return __KthNode(pRoot, k);
    }

    TreeNode* __KthNode(TreeNode* root, int& k) {
    	if (NULL == root) {
    		return NULL;
    	}

    	TreeNode* target = NULL;

        target = __KthNode(root->left, k);
        if (NULL == target) {
        	if (1 == k) {
        		target = root;
        	}
        	--k;
        }
        if (NULL == target) {
        	target = __KthNode(root->right, k);
        }

        return target;
    }
};