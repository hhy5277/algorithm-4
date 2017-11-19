/*
Given an index k, 
return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        if(!n) return 0;
        if(1 == n)
            return triangle[0][0];
        
        vector<int> dp; // 保存着到达每一层的i元素时候最小的值（到达每一层都需要更新这个数组）
        dp.push_back(triangle[0][0]);
        
        for (int i = 1; i < n; ++i) {
            vector<int> new_dp;
            new_dp.push_back(dp[0] + triangle[i][0]);
            
            for (int j = 1; j < i; j++) {
                new_dp.push_back(min(dp[j-1], dp[j]) + triangle[i][j]);
            }
            
            new_dp.push_back(dp[i - 1] + triangle[i][i]);
            
            dp.swap(new_dp);
        }
        
        int minv = dp[0];
        
        for(int i = 1; i < n; ++i)
            minv = min(minv, dp[i]);
        
        return minv;
    }
};