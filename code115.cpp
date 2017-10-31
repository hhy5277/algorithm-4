/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (NULL == pHead) {
        	return NULL;
        }

        ListNode* pre_node = NULL;
        ListNode* p_node = pHead;
        ListNode* p_node_next = p_node->next;

        while (p_node != NULL && p_node_next != NULL) {
        	while (p_node_next != NULL && p_node_next->val != p_node->val) {
        		pre_node = p_node;
        		p_node = p_node_next;
        		p_node_next = p_node_next->next;
        	}

        	int value = p_node->val;

        	while (p_node_next->val == value) {
        		delete p_node;
        		p_node = p_node_next;
        		p_node_next = p_node_next->next;
        	}

        	delete p_node;
        	p_node = p_node_next;

        	if (p_node_next != NULL) {
        		p_node_next = p_node_next->next;
        	}

        	pre_node->next = p_node;
        }

        return pHead;
    }
};