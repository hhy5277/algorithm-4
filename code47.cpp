/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：
用两个指针
一个指针用来固定，
另一个指针用来移动，遍历后面的节点，从而找出那些节点元素值相同的节点
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL) {
    		return head;
    	}

    	ListNode* current_node = head;
    	ListNode* move_node = head->next;

    	while (move_node != NULL) {
    		while ((move_node != NULL) && (move_node->val == current_node->val)) {
    			current_node->next = move_node->next;
    			move_node = move_node->next;
    		}

    		current_node = move_node;
    		if (move_node != NULL) {
    		    move_node = move_node->next;
    		}
    	}

        return head;
    }
};