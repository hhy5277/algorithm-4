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
先求出环中的节点个数n，然后先让快指针走n步。然后快慢指针一起走。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (NULL == head) {
        	return NULL;
        } 

        ListNode *fast = head, *slow = head;

        while (fast->next != NULL && fast->next->next != NULL) { // 此时fast 和 slow 会在环中相遇
        	fast = fast->next->next;
        	slow = slow->next;

        	if (fast == slow) {
        		break;
        	}
        }

        if (NULL == fast->next || NULL == fast->next->next) {
        	return NULL;
        }

        int count = 1;
        fast = fast->next;

        while (fast != slow) {
            fast = fast->next;
            ++count;
        }

        fast = head;
        slow = head;

        for (int i = 0; i < count; ++i) {
            fast = fast->next;
        }

        while (slow != fast) {
        	slow = slow->next;
        	fast = fast->next;
        }

        return fast;
    }
};