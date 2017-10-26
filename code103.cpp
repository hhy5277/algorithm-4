/**
 * Definition for binary tree
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
        int pre_length = preorder.size();
        int in_length = inorder.size();

        if (pre_length != in_length) {
        	return NULL;
        }

        if (pre_length == 0 && in_length == 0) {
        	return NULL;
        }

        return __buildTree(preorder, inorder, 0, pre_length - 1, 0, in_length - 1);
        

    }

    TreeNode* __buildTree(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
    	int rootValue = preorder[pre_start]; // 根节点的值
    	TreeNode* root = new TreeNode(rootValue);

    	if (pre_start == pre_end) {
    		if (in_start == in_end) {
    			return root;
    		}
    	}
        
        // 在中序遍历里面寻找根节点
        int rootInorder;

        for (int i = in_start; i <= in_end; i++) {
        	if (inorder[i] == rootValue) {
                rootInorder = i;
        	}
        }

        int left_length = rootInorder - in_start;
        int left_pre_end = pre_start + left_length;
        
        // 构建左子树
        if (left_length > 0) { // 当有左子树时，才需要构建左子树
            root->left = __buildTree(preorder, inorder, pre_start + 1, left_pre_end, in_start, rootInorder - 1);
        }
        // 构建右子树
        // pre_end - pre_start 是左子树加上右子树的节点总个数
        //所以，当left_length（左子树节点个数）小于总的个数，说明有右子树，所以需要构建右子树
        if (left_length < pre_end - pre_start) { // 
            root->right = __buildTree(preorder, inorder, left_pre_end + 1, pre_end, rootInorder + 1, in_end);
        }

        return root;
    }
};