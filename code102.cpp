/*
输入一个链表，从尾到头打印链表每个节点的值。
*/
/*
思路：
因为遍历链表的顺序是从头到尾，而输出的顺序是从尾到头，这种特点很符合栈的特点。
所以，使用栈来实现。
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        std::vector<int> v;

        if (NULL == head) {
        	return v;
        }

        stack<int> stk;
        ListNode* current_node = head;

        while (current_node != NULL) {
        	stk.push(current_node->val);
        	current_node = current_node->next;
        }

        while (!stk.empty()) {
        	v.push_back(stk.top());
        	stk.pop();
        }

        return v;
    }
};