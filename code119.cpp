/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    	if (NULL == pHead1) {
    		return pHead2;
    	}
    	if (NULL == pHead2) {
    		return pHead1;
    	}

    	ListNode* merge_head = NULL;

    	if (pHead1->val < pHead2->val) {
    		merge_head = pHead1;
    		merge_head->next = Merge(pHead1->next, pHead2);
    	}
    	else {
    		merge_head = pHead2;
    		merge_head->next = Merge(pHead1, pHead2->next);
    	}

    	return merge_head;
    }
};