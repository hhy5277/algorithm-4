/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
思路一：
用栈来模仿递归的过程
每次pop()一次，代表访问了一次该节点。当第二次访问的时候，就可以打印该节点了
可以先画一棵比较完整的二叉树来模拟过程，然后写出代码
思路二：
可以建立线索二叉树来遍历整棵树
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (NULL == root) {
        	return v;
        }

        stack<TreeNode*> stk;
        stk.push(root);
        stk.push(root);

        while (!stk.empty()) {
        	TreeNode* temp = stk.top(); // 只是起到一个保存记录的作用，并不代表访问了这个节点，访问的操作是pop()
        	stk.pop(); // 访问一次该节点
            
            if ((!stk.empty()) && (temp == stk.top())) {
            	if (temp->left != NULL) {
                	stk.push(temp->left);
                	stk.push(temp->left);
            	}
            }
            else { // 当第二次访问到这个节点的时候，可以打印了
            	v.push_back(temp->val);
                if (temp->right != NULL) {
                	stk.push(temp->right);
                	stk.push(temp->right);
                }
            }
        }

        return v;
    }
};