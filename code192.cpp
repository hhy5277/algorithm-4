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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	int n1 = preorder.size();
    	int n2 = inorder.size();

    	if (n1 != n2 || 0 == n1 || 0 == n2) {
    		return NULL;
    	}

    	return __buildTree(preorder, 0, n1 - 1, inorder, 0, n2 - 1);
    }

    TreeNode* __buildTree(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
    	if (pre_start > pre_end) {
    		return NULL;
    	}

    	TreeNode* root = new TreeNode(preorder[pre_start]);

    	int length = 0;
        for (int i = in_start; i != in_end; ++i) {
        	if (preorder[pre_start] == inorder[i]) {
        		break;
        	}
        	++length;
        }
        
        if (length >= 0) { // 这个很关键
        	root->left = __buildTree(preorder, pre_start + 1, pre_start + length, inorder, in_start, in_start + length - 1);
        }
        if (pre_start + length + 1 <= pre_end) {
        	root->right = __buildTree(preorder, pre_start + length + 1, pre_end, inorder, in_start + length + 1, in_end);
        }
        
        return root;
    }
};