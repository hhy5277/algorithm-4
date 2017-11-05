/*
题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
    	vector<vector<int> > vv;
    	vector<int> v;

    	if (NULL == root) {
    		return vv;
    	}

    	int current_sum = 0;

    	__FindPath(root, expectNumber, current_sum, vv, v);

    	return vv;
    }

    void __FindPath(TreeNode* root, int expect_number, int current_sum, vector<vector<int> >& vv, std::vector<int>& v) {
    	if (root == NULL) {
    		return ;
    	}

        current_sum += root->val;
        v.push_back(root->val);

        if (root->left == NULL && root->right == NULL && current_sum == expect_number) {
        	vv.push_back(v);
        }

    	__FindPath(root->left, expect_number, current_sum, vv, v);
    	__FindPath(root->right, expect_number,current_sum, vv, v);

        v.pop_back();
    }
};