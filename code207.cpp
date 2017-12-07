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
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head) {
        	return NULL;
        }

        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *front = new_head;
        ListNode *end = head;

        while (end != NULL && end->next != NULL) {
        	ListNode *temp = end->next->next;
        	front->next = end->next;
        	end->next->next = end;
        	end->next = temp;

        	front = end;
        	end = end->next;
        }

        return new_head->next;
    }
};