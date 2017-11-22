/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/
/*
思路：
中序遍历二叉树，出现的节点的值会升序排序，如果有两个节点位置错了，那肯定会出现降序。
设置一个pre节点指针，记录当前节点中序遍历时的前节点，如果当前节点小于pre节点的值，说明需要调整次序。
如果在中序遍历时节点值出现了两次降序，第一个错误的节点为第一次降序时较大的节点，第二个错误节点为第二次降序时较小的节点。
比如，原来的搜索二叉树在中序遍历的节点值依次为{1,2,3,4,5}，如果因为两个节点位置错了而出现{1,5,3,4,2}，
第一次降序为5->3，所以第一个错误节点为5，第二次降序为4->2,所以第二个错误节点为2，将5和2换过来就可以恢复。
*/
 class Solution {
 public:
	 TreeNode* mistake1;
	 TreeNode* mistake2;
	 TreeNode* pre=NULL;

	 void recoverTree(TreeNode* root) {
		 recursive_traversal(root);
		 if (mistake1 != NULL && mistake2 != NULL)
		 {
			 swap(mistake1->val, mistake2->val);
		 }
	 }

	 //递归中序遍历二叉树
	 void recursive_traversal(TreeNode* root){
		 if (root == NULL)
			 return;
		 if (root->left != NULL)
		 {
			 recursive_traversal(root->left);
		 }
		 if (pre != NULL && pre->val>root->val)
		 {
			 if (mistake1 == NULL)
			 {
				 mistake1 = pre;
				 mistake2 = root;
			 }
			 else // 当出现两次降序的时候，会执行这段代码
			 {
				 mistake2 = root;
			 }
		 }

		 pre = root; // 当 root->left == NULL 的时候，此时，pre会是下一个栈帧（或者回退后的栈帧）中root的前一个节点（针对中序遍历序列）

		 if (root->right != NULL)
		 {
			 recursive_traversal(root->right);
		 }
	 }
 };
