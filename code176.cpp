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
思路：
使用队列来保存每一层的节点
如果当前遍历到的深度是奇数的话，那么按照原来的队列的序列输出
如果当前遍历到的深度是偶数的话，使用栈来倒序输出队列里面的序列
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > vv;
        queue<TreeNode*> q;
        int depth = 1;

        if (NULL == root) {
        	return vv;
        }

        q.push(root);
        while (!q.empty()) {
        	int n = q.size();
        	vector<int> v;
        	if (depth % 2 == 1) { // 按照队列中原来的序列输出
        		for (int i = 0; i < n; ++i) {
                    v.push_back(q.front()->val);
                    if (q.front()->left != NULL) {
                    	q.push(q.front()->left);
                    }
                    if (q.front()->right != NULL) {
                    	q.push(q.front()->right);
                    }

                    q.pop();
        		}

        		
        	}
        	else { // 按照用来的序列倒序输出
        		stack<int> stk;
        		for (int i = 0; i < n; ++i) {
        			stk.push(q.front()->val);
        			if (q.front()->left != NULL) {
                    	q.push(q.front()->left);
                    }
                    if (q.front()->right != NULL) {
                    	q.push(q.front()->right);
                    }

                    q.pop();
        		}

        		while(!stk.empty()) {
                    v.push_back(stk.top());
                    stk.pop();
                }
        	}

        	++depth;

        	vv.push_back(v);
            v.clear();
        }

        return vv;
    }
};