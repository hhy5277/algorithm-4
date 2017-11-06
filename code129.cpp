/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (NULL == pRootOfTree) {
        	return NULL;
        }

    	TreeNode* last_node_in_list = NULL;

    	TreeNode* list_head = ConvertNode(pRootOfTree, last_node_in_list);

    	while (list_head != NULL && list_head->left != NULL) {
    		list_head = list_head->left;
    	}

    	return list_head;
    }

    TreeNode* ConvertNode(TreeNode* node, TreeNode* last_node_in_list) {
        TreeNode* current_node = node;

        if (current_node->left != NULL) {
        	last_node_in_list = ConvertNode(current_node->left, last_node_in_list);
        }

        current_node->left = last_node_in_list;
        if (last_node_in_list != NULL) {
        	last_node_in_list->right = current_node;
        }

        last_node_in_list = current_node;

        if (current_node->right != NULL) {
        	last_node_in_list = ConvertNode(current_node->right, last_node_in_list);
        }

        return last_node_in_list;
    }
};