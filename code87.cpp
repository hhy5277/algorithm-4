/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
/*
思路：
如果说，两个链表都是一样长的，那么，这是很好判断的，只需要使用两个指针，分别把两个链表遍历一次即可。
但是，如果两个链表的长度是不同的，那么，就需要一些骚的操作了。也就是，谁先遍历完，就让这个指针遍历另一个链表，达到两个链表的长度是“假相等”的效果。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ((headA == NULL) || (headB == NULL)) {
        	return NULL;
        }

        ListNode* list_a = headA;
        ListNode* list_b = headB;

        while ((list_a != NULL) || (list_b != NULL)) {
        	if (list_a == list_b) {
        		return list_a;
        	}

            list_a = list_a->next;
            list_b = list_b->next;

            if (list_a == list_b) { // 当list_a 和 list_b相交时候，或者list_a和list_b都为NULL的时候，返回。
            	return list_a;
            }
            if (list_a == NULL) {
            	list_a = headB;
            }
            if (list_b == NULL) {
            	list_b = headA;
            }
        }

        return NULL;
    }
};