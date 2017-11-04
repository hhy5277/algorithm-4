/*
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        std::vector<int> v;
        if (NULL == root) {
        	return v;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
        	int n = q.size();

        	for (int i = 0; i < n; ++i) {
        		if (q.front()->left != NULL) {
        			q.push(q.front()->left);
        		}
        		if (q.front()->right != NULL) {
        			q.push(q.front()->right);
        		}

        		v.push_back(q.front()->val);
        		q.pop();
        	}
        }

        return v;
    }
};