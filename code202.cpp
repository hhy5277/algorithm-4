/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/
/*
思路：
类似这种找出所有满足结果的题目，可以使用回溯法
*/
class Solution {
public:
    void dfs(vector<int>& candidates, int target, int index, int sum, vector<int>& curr, vector<vector<int>>& retval){
        if(sum == target){
            retval.push_back(curr);

            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(sum + candidates[i] > target) break;
            curr.push_back(candidates[i]);
            dfs(candidates, target, i, sum+candidates[i], curr, retval);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> retval;
        vector<int> curr;
        dfs(candidates, target, 0, 0, curr, retval);

        return retval;
    }
};