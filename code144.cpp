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