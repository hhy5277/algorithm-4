/*
思路：
需要一个额外的头结点
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *sortedHead = new ListNode(-1);

        while(head != NULL) {
            //保存head位置
            ListNode *temp = head->next;
            ListNode *cur = sortedHead;
            while(cur->next != NULL && cur->next->val < head->val)
            {
                cur = cur->next;
            }
            //插入
            head->next = cur->next;
            cur->next = head;
            //恢复head
            head = temp;
        }

        return sortedHead->next;
    }
};