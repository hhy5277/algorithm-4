/*
思路：
首先对二分搜索树进行中序遍历（实际上当使用哈希表来计算元素出现的次数的时候，就没有用到中序遍历的排好序的作用了）
然后再用哈希表统计每个元素出现的次数
然后找出出现次数（max_times）最多的哪个元素
当这个元素出现的次数等于max_times的时候，那么就把这个元素添加到容器里面
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
public:
    vector<int> findMode(TreeNode* root) {
        std::vector<int> v;
        std::vector<int> res;

        if (root == NULL) {
        	return v;
        }
        
        __findMode(root, v);

        std::map<int, int> m;

        int n = v.size();

        for (int i = 0; i < n; i++) {
        	m[v[i]]++;
        }

        int max_times = INT_MIN;

        for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i) {
        	max_times = max(max_times, i->second);
        }
        
        for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i) {
        	if (i->second == max_times) {
                res.push_back(i->first);
        	}
        }


        return res;
    }

    void __findMode(TreeNode* root, vector<int> &v) {
        if (root == NULL) {
        	return ;
        }
        
        __findMode(root->left, v);
        v.push_back(root->val);
        __findMode(root->right, v);
    }
};