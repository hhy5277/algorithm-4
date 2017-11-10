/*
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (NULL == pRoot) {
        	return true;
        }

        return __IsBalanced_Solution(pRoot);
    }

    bool __IsBalanced_Solution(TreeNode* root) {
        if (NULL == root) {
        	return true;
        }

        int left_depth = TreeDepth(root->left);
        int right_depth = TreeDepth(root->right);

        if (abs(left_depth - right_depth) > 1) {
        	return false;
        }
        
        return __IsBalanced_Solution(root->left) && __IsBalanced_Solution(root->right);
    }

    int TreeDepth(TreeNode* pRoot) {
    	if (NULL == pRoot) {
    		return 0;
    	}

    	queue<TreeNode*> q;

    	q.push(pRoot);
    	int depth = 0;

    	while (!q.empty()) {
    		int n = q.size();

    		for (int i = 0; i < n; ++i) {
    			if (q.front()->left != NULL) {
    				q.push(q.front()->left);
    			}
    			if (q.front()->right != NULL) {
    				q.push(q.front()->right);
    			}

    			q.pop();
    		}

    		++depth;
    	}

    	return depth;
    }
};