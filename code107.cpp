/*
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (NULL == pNode) {
        	return NULL;
        }

        if (pNode->right != NULL) {
        	TreeLinkNode* pNode_right = pNode->right;

        	while (pNode_right->left != NULL) {
        		pNode_right = pNode_right->left;
        	}

        	return pNode_right;
        }
        else if (pNode->next != NULL) {
        	while (pNode->next != NULL) {
        		TreeLinkNode* pNode_parent = pNode->next;
        		if (pNode == pNode_parent->left) {
        			return pNode_parent;
        		}
        		pNode = pNode->next;
        	}
        }

        return NULL;
    }
};