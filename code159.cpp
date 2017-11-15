/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.


*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (NULL == head) {
    		return NULL;
    	}
        
        RandomListNode* cur_node = head;

        while (cur_node != NULL) {
        	// 深拷贝一个节点
    	    RandomListNode* new_node = new RandomListNode(cur_node->label);
    	    // 把拷贝出来的节点连接到原来的链表中
    	    new_node->next = cur_node->next;
    	    cur_node->next = new_node;

    	    cur_node = cur_node->next->next;
        }

        // 开始修改副本链表的random指针
        cur_node = head;

        while (cur_node != NULL) {
        	if (cur_node->random != NULL) { // 当random指向其他节点的时候，复制出来的节点才需要改变random指针
        	    cur_node->next->random = cur_node->random->next;
        	}

            cur_node = cur_node->next->next;
        }

        // 开始分离出深拷贝的那个链表（修改next指针）
        cur_node = head;
        RandomListNode* copy_node_head = head->next;
        RandomListNode* copy_node_cur = copy_node_head;
        while (cur_node != NULL) {
        	cur_node->next = cur_node->next->next;
        	if (copy_node_cur->next != NULL) {
        		copy_node_cur->next = copy_node_cur->next->next;
        	}
        	else {
        		copy_node_cur->next = NULL;
        	}

        	cur_node = cur_node->next;
        	copy_node_cur = copy_node_cur->next;
        }

        return copy_node_head;
    }
};