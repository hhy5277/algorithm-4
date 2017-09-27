/*
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
the linked list should become 1 -> 2 -> 4 after calling your function.
*/
/*
思路：
从链表中，删除指定的节点，
但又没有给出前指针，所以先交换当前节点和下一节点的值，
然后删除下一节点即可。
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
    void deleteNode(ListNode* node) {
    	node->val = node->next->val;
    	node->next = node->next->next;
    }
};