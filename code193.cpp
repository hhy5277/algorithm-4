/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
关键点：
需要考虑比较特殊的情况，例如 k 大于链表的长度的时候，要如何处理。这里，我们让k = (k % 链表的长度)
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return head;

        ListNode *p = head;

        //求链表的长度
        int len = 0;
        while (p)
        {
            len++;
            p = p->next;
        }

        k %= len;

        //k<=0时，原链表不旋转
        if (k <= 0)
            return head;

        int index = 1;      
        //寻找右旋k位置后，链表的首结点
        p = head;
        while (index < (len - k) && p->next != NULL)
        {
            index++;
            p = p->next;
        }

        ListNode *ret = p->next, *q = p;

        //原链表寻找尾结点，将其链接到head
        while (p->next)
            p = p->next;
        p->next = head;

        //前部分尾结点设为NULL
        q->next = NULL;
        return ret;

    }
};