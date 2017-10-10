/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/
/*
思路：
层序遍历这棵树，如果节点为空，那么就用0来填充。
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
        	return true;
        }

        queue<TreeNode*> q;

        q.push(root);
        
        while (!q.empty()) {
        	int n = q.size();
        	std::vector<int> v;

        	for (int i = 0; i < n; i++) {
        		if (q.front()->left != NULL) {
        			q.push(q.front()->left);
        			v.push_back(q.front()->left->val);
        		}
        		else {
        			v.push_back(0);
        		}
        		if (q.front()->right != NULL) {
        			q.push(q.front()->right);
        			v.push_back(q.front()->right->val);
        		}
        		else {
        			v.push_back(0);
        		}

        		q.pop();
        	}

        	if (!__isSymmetric(v)) {
                return false;
        	}
        }

        return true;
    }
    
    /*
    作用：
    用来判断每一层是否对称。
    
    参数1：存放每一层节点值的数组。
    */
    bool __isSymmetric(vector<int> v) {
    	int n = v.size();

    	for (int i = 0, j = n - 1; i <= j; i++, j--) {
    		if (v[i] != v[j]) {
    			return false;
    		}
    	}

    	return true;
    }
};