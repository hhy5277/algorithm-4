/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
/*
思路：
先把后半部分的链表逆置，然后再把逆置后的链表插入到前半部分链表适当的位置
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (NULL == head) {
        	return ;
        }

        ListNode* fast;
        ListNode* slow;
        fast = head;
        slow = head;

        while (fast->next != NULL && fast->next->next != NULL) {
        	fast = fast->next->next;
        	slow = slow->next; // 最终，slow指针指向链表的中间节点
        }

        ListNode* cur1 = head;
        ListNode* cur2 = reverseList(slow->next);

        

        slow->next = NULL;

        while (cur1 != NULL) {
        	if (NULL == cur2) {
        	    return;
            }
            
        	ListNode* temp = cur2->next;
        	cur2->next = cur1->next;
        	cur1->next = cur2;
        	cur2 = temp;
        	cur1 = cur1->next->next;
        }
    }

    ListNode* reverseList(ListNode* head) {
    	if (NULL == head) {
    		return NULL;
    	}

    	ListNode* front;
    	ListNode* cur;
    	ListNode* end;
    	front = NULL;
    	cur = head;
    	end = head->next;

    	while (cur != NULL) {
    		cur->next = front;
    		front = cur;
    		cur = end;
    		if (end != NULL) {
                end = end->next;
    		}
    	}

    	return front;
    }
};