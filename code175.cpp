/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
/*
思路：
递归的去寻找单链表的中间节点，
从头结点开始找到的中间节点作为树的左孩子，
从根节点的下一个节点开始找到的中间节点作为树的右孩子，
递归的结束条件是这个节点为空
*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if (NULL == head) {
    		return NULL;
    	}

        return __sortedListToBST(head);
    }
    
    /*
    作用：把单链表转化为平衡的BST
    返回值：BST的根节点
    参数1：需要查找中间节点的那个单链表的起始节点
    */
    TreeNode* __sortedListToBST(ListNode* head) {
        if (NULL == head->next) { // 当链表只有一个节点的时候，直接返回这个节点
        	return new TreeNode(head->val);
        }

        if (NULL == head->next->next) { // 当链表有两个节点的时候所做的操作
        	TreeNode* root = new TreeNode(head->next->val);
        	TreeNode* left_child = new TreeNode(head->val);
        	root->left = left_child;

        	return root;
        }

    	ListNode* middle_node = findListMiddleNode(head);
    	TreeNode* root = new TreeNode(middle_node->val);

    	root->left = __sortedListToBST(head);
    	root->right = __sortedListToBST(middle_node->next);
        
    	return root;
    }
    
    /*
    作用：查找单链表的中间节点
    参数1：起始节点
    */
    ListNode* findListMiddleNode(ListNode* head) {
        if (NULL == head) {
        	return NULL;
        }

    	ListNode *slow = head, *fast = head, *pre_slow = NULL;

    	while (fast->next != NULL && fast->next->next != NULL) {
    		pre_slow = slow;
    		slow = slow->next;
    		fast = fast->next->next;
    	}

    	if (pre_slow != NULL) {
    		pre_slow->next = NULL;
    	}

    	return slow;
    }
};