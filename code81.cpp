/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：
首先要想到使用两个指针：pre和cur
其次是被删除的节点可能是头结点，所以，我们需要构造一个新的头结点。
pre只有当cur的值不等于val的时候，才需要移动。
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	if (head == NULL) {
    		return head;
    	}

        ListNode* new_head = new ListNode(-1);
        new_head->next = head;

        ListNode* current_node = head;
        ListNode* pre = new_head;

        while (current_node != NULL) {
            if (current_node->val == val) {
            	// pre->next = pre->next->next;
            	pre->next = current_node->next;
            }
            else {
            	pre = pre->next;
            }

            current_node = current_node->next;
        }

        return new_head->next;
    }
};