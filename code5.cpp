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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *headNode = new ListNode(0), *currentNode = headNode;
    	ListNode *p = l1, *q = l2; // 一般我们不会去直接操作传过来的参数，所以另外保存它们
    	int carry = 0, x, y, sum;
    	while (p != NULL || q != NULL) {
    		x = (p != NULL) ? p->val : 0;
    		y = (q != NULL) ? q->val : 0;
            
            sum = x + y + carry;
            currentNode->next = new ListNode(sum % 10);
            currentNode = currentNode->next;
            carry = sum / 10;

            if ((p != NULL) && (p->next != NULL)) {
            	p = p->next;
            }
            else {
            	p = NULL;
            }

            if ((q != NULL) && (q->next != NULL)) {
            	q = q->next;
            }
            else {
            	q = NULL;
            }
    	}

    	if  (carry > 0) {
    		currentNode->next = new ListNode(carry);
    	}

    	return headNode->next;
    }
};