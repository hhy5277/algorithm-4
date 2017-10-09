/*
注意：重复的元素也要插入进去，而不能忽略
思路：
维护两个指针对应两个链表，以一条链表为基准，比如说l1，
那么如果l1当期那的元素比较小，那么直接移动l1即可，
否则将l2当前的元素插入到l1当前元素的前面。
算法时间复杂度是O(m+n),m和n分别是两条链表的长度，空间复杂度是O(1)
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (l1 == NULL) {
    		return l2;
    	}
    	if (l2 == NULL) {
    		return l1;
    	}

        ListNode* l1_header = new ListNode(0);
        l1_header->next = l1;
        ListNode* hello_node = l1_header;
        ListNode* l1_current = l1;
        ListNode* l2_current = l2;

        while ((l1_current != NULL) && (l2_current != NULL)) {
        	if (l2_current->val >= l1_current->val) {
        		l1_header = l1_current;
        		l1_current = l1_current->next;
        	}
        	else if (l2_current->val < l1_current->val) {
        		ListNode* temp_node = l2_current;
        		l2_current = l2_current->next;
        		temp_node->next = l1_current;
        		l1_header->next = temp_node;
        		l1_header = l1_header->next;
        	}
        }

        if (l2_current != NULL) {
        	l1_header->next = l2_current;
        }

        return hello_node->next;
    }
};