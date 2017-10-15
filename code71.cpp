/*
Given a linked list, determine if it has a cycle in it.
*/
/*
思路：
链表的环相当于一个圆形操场。
假设有两个人在圆形操场上无限循环的跑，那么速度快的一定能追得上速度慢的。
同理，若要判断一个链表是否有环，可设计快慢指针，当快慢指针都进入环的时候，
若最终两个指针相遇，必可说明链表存在环。
下面就要考虑快慢指针的步长，
从跑操场的情况来看，不管慢的有多慢，快得有多快，最终肯定能相遇。
同理，链表中，也可随意指定快慢指针的步长，无非就是跑的圈数多少的问题。 
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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while ((fast != NULL) && (slow != NULL) && (fast->next != NULL)) {
        	slow = slow->next; // 慢指针的步长为1
        	fast = fast->next->next; // 快指针的步长为2

        	if (fast == slow) {
        		return true;
        	}
        }

        return false;
    }
};