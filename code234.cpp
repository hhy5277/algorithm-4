/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/
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
关键是要删除的节点是头节点。
判断是否是删除头节点的条件是：
当first指针先走完n步之后，如果指向NULL，那么说明是要删除头节点。
这时候，直接返回head->next即可。
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first, *second;
        first = head;

        for (int i = 0; i < n; ++i) {
        	first = first->next;
        }

        if (first == NULL) {
        	return head->next;
        }

        second = head;

        while (first->next != NULL) {
        	first = first->next;
        	second = second->next;
        }

        second->next = second->next->next;

        return head;
    }
};