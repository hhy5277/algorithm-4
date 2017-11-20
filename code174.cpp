/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root) {
        	return ;
        }

        queue<TreeLinkNode*> q;
        q.push(root);

        while (!q.empty()) {
        	int n = q.size();

        	for (int i = 0; i < n; ++i) {
        		TreeLinkNode* temp = q.front();
        		q.pop();
                
                if (i == n - 1) {
              		temp->next = NULL;
                } 
        		else {
        			temp->next = q.front();
        		}

        		if (temp->left != NULL) {
        			q.push(temp->left);
        		}
        		if (temp->right != NULL) {
        			q.push(temp->right);
        		}
        	}
        }
    }
};