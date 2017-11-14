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
        
        while(st.size())
        {
            temp = st.top();
            st.pop();
            if(st.size() && st.top() == temp)
            {
                ans.push_back(temp->val);
                st.pop();
                continue;
            }
            
            st.push(temp);
            st.push(temp);
            if(temp->right)st.push(temp->right);
            if(temp->left)st.push(temp->left);
        }
        return ans;
    }
};