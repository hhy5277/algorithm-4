/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root) return ans;
        
        stack<TreeNode*> st;
        st.push(root);

        TreeNode* temp;
        
        // 先把所有的节点压入栈中，再来开始打印节点（符合后序遍历的定义：先访问左右子树，再来打印根节点）
        // 所以，当一个节点还有左右子树的时候，需要继续把左右子树的根节点压栈（先压右节点，再压左节点）
        while(st.size())
        {
            temp = st.top();
            st.pop(); // 出栈，实际上对应着后序遍历中，对这个节点进行了一次访问

            if(st.size() && st.top() == temp) // 当一个节点没有左右子树的时候，st.top() == temp成立（此时，对左子树的递归也将结束）
            {
                ans.push_back(temp->val);
                st.pop();
                continue;
            }
            
            st.push(temp); // 把temp压入两次的原因是为了知道出栈的时候， 出栈到哪个元素为止（因为代表了栈中的那个节点被访问了两次。所以，下次判断st.top() == temp会成立）。
            st.push(temp);
            // 先把右节点压栈，再把左节点压栈。这样的话，出栈的时候，就是先出左节点，再出右节点（符合遍历的规定--先左子树，后右子树）。
            if(temp->right)st.push(temp->right);
            if(temp->left)st.push(temp->left);
        }

        return ans;
    }
};