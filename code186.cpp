/*
题目描述
输入一个链表，从尾到头打印链表每个节点的值。
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
/*
思路：
使用递归来解决
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
    	vector<int> v;

        if (NULL == head) {
            return v;
        }

        __printListFromTailToHead(head, v);

        return v;
    }

    void __printListFromTailToHead(ListNode* node, vector<int>& v) {
        if (NULL == node) {
        	return ;
        }

        __printListFromTailToHead(node->next, v);

        v.push_back(node->val);
    }
};