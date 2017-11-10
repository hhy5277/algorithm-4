/*
题目描述
输入两个链表，找出它们的第一个公共结点。
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (NULL == pHead1 || NULL == pHead2) {
        	return NULL;
        }

        int lenght_1 = 1;
        int lenght_2 = 1;
        ListNode* cur_1 = pHead1;
        ListNode* cur_2 = pHead2;

        while (cur_1->next != NULL) {
        	cur_1 = cur_1->next;
        	++lenght_1;
        }

        while (cur_2->next != NULL) {
        	cur_2 = cur_2->next;
        	++lenght_2;
        }

        int diff;

        cur_1 = pHead1;
        cur_2 = pHead2;

        if (lenght_1 > lenght_2) {
        	diff = lenght_1 - lenght_2;
        	for (int i = 0; i < diff; ++i) {
        		cur_1 = cur_1->next;
        	}
        }

        if (lenght_2 >= lenght_1) {
        	diff = lenght_2 - lenght_1;
        	for (int i = 0; i < diff; ++i) {
        		cur_2 = cur_2->next;
        	}
        }

        while ((cur_1 != cur_2) && (cur_1 != NULL) && (cur_2 != NULL)) {
            cur_1 = cur_1->next;
            cur_2 = cur_2->next;
        }

        return cur_1;
    }
};