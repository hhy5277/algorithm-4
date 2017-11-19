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
public:
    int dfs(TreeNode *root, int& d){
        if(!root) return 0;
        int l = dfs(root->left, d);
        int r = dfs(root->right, d);
        
        if(l < 0) l = 0; // 在左子树的值小于0的时候，就不需要加上这个值了，所以赋予0
        if(r < 0) r = 0; // 在右子树的值小于0的时候，就不需要加上这个值了，所以赋予0
        
        d = max(d, l + r + root->val); // 因为是一条路径，在得到底层返回的较大值之后，还要加上父节点root->val，这样才能把左右节点连接起来，形成一条路径
        
        return max(r, l) + root->val; // 返回给上一层的值是左子树和右子树中较大的那一个值再加上root->val
    }
    
    int maxPathSum(TreeNode* root) {
        int d = INT_MIN;
        dfs(root, d);

        return d;
    }
};