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
    ListNode* deleteDuplicates(ListNode* head) {
        if (NULL == head) {
        	return NULL;
        }

        ListNode* temp_head = new ListNode(INT_MAX);
        temp_head->next = head;
        ListNode* pre = temp_head;
        ListNode* cur = head;

        while (cur != NULL) {
            while ((cur->next != NULL) && (pre->next->val == cur->next->val)) { // 当pre->next->val == cur->next->val，移动cur
            	cur = cur->next;
            }
            
            if (pre->next == cur) { // 当没有连续的元素相同的时候，就直接移动pre
            	pre = pre->next;
            }
            else { // 当有连续的元素相同的时候，前面的操作就会移动cur，此时，pre->next != cur
            	pre->next = cur->next;
            }

            cur = cur->next;
        }

        return temp_head->next;
    }
};