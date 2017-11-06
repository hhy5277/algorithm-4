/*
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，
一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
    	if (NULL == pHead) {
    		return NULL;
    	}

        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        RandomListNode* cloned_head_node = ReconnectNodes(pHead);

        return cloned_head_node;
    }

    void CloneNodes(RandomListNode* pHead) {
    	RandomListNode* current_node = pHead;
    	while (current_node != NULL) {
    		RandomListNode* cloned_node = new RandomListNode(current_node->label);

    		cloned_node->next = current_node->next;
    		current_node->next = cloned_node;

    		current_node = cloned_node->next;
    	}
    }

    void ConnectSiblingNodes(RandomListNode* pHead) {
    	RandomListNode* current_node = pHead;
    	while (current_node != NULL) {
    		if (current_node->random != NULL) {
    			current_node->next->random = current_node->random->next;
    		}

    		current_node = current_node->next->next;
    	}
    }

    RandomListNode* ReconnectNodes(RandomListNode* pHead) {
        RandomListNode* current_node = pHead;
        RandomListNode* cloned_head_node = current_node->next;
        RandomListNode* current_cloned_node = cloned_head_node;

        current_node->next = current_cloned_node->next;
        current_node = current_node->next; // 因为，我们是通过current_node来结束循环的，来决定是否需要继续把复制出来的节点继续连接。所以，我们让current_node在current_cloned_node的后面

        while (current_node != NULL) {
        	current_cloned_node->next = current_node->next;
        	current_cloned_node = current_cloned_node->next;

        	current_node->next = current_cloned_node->next;
        	current_node = current_node->next;
        }

        return cloned_head_node;
    }
};