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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
    	ListNode* meeting_node = MeetingNode(pHead);
        
        if (meeting_node == NULL) {
        	return NULL;
        }

    	ListNode* p_node = meeting_node->next;

    	int count = 1;

    	while (p_node != meeting_node) {
    		++count;
    		p_node = p_node->next;
    	}

    	ListNode* slow = pHead;
    	ListNode* fast = pHead;

    	for (int i = 0; i < count; ++i) {
    		fast = fast->next;
    	}

    	while (slow != fast) {
    		slow = slow->next;
    		fast = fast->next;
    	}

    	return fast;
    }

    ListNode* MeetingNode(ListNode* pHead) {

        if (NULL == pHead) {
        	return NULL;
        }

        ListNode* slow = pHead;

        if (slow->next == NULL) {
        	return NULL;
        }

        ListNode* fast = slow->next;

        while (fast != slow) {
        	slow = slow->next;
        	fast = fast->next;
        	if (fast == NULL) {
        		return NULL;
        	}
        	fast = fast->next;
        }

        return fast;
    }
};