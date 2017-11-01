/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (NULL == pListHead || 0 == k) {
        	return NULL;
        }

        ListNode* fast = pListHead;
        ListNode* slow = NULL;

        for (int i = 0; i < k - 1; ++i) {
        	if (fast->next != NULL) {
        		fast = fast->next;
        	}
        	else {
        		return NULL;
        	}
        }

        slow = pListHead;

        while (fast->next != NULL) {
        	fast = fast->next;
        	slow = slow->next;
        }

        return slow;
    }
};