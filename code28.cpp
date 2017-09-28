/*
Given scores of N athletes, 
find their relative ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, 
so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, 
you just need to output their relative ranks according to their scores.
*/
/*
可以用map来解决，
将nums中的元素值作为map的index从而实现将nums排序，
同时保存nums的index到map中
*/
class Solution {  
public:  
    vector<string> findRelativeRanks(vector<int>& nums) {  
        vector<string> res(nums.size());  
        map<int,int>ma;  
        for(int i=0;i!=nums.size();++i)  
            ma[nums[i]]=i;  
        int count=1;  
        for(map<int,int>::reverse_iterator it=ma.rbegin();it!=ma.rend();++it,++count)  
        {  
            if(count==1)  
                res[it->second]="Gold Medal";  
            else if(count==2)  
                res[it->second]="Silver Medal";  
            else if(count==3)  
                res[it->second]="Bronze Medal";  
            else  
                res[it->second]=to_string(count);  
        }  
        return res;  
          
    }  
};