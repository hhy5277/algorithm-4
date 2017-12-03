/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
/*
在原数组上进行元素交换，采用桶排序的思想。
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int i=0,n=nums.size(),temp;
        
        for(;i<n;)
        {
            if(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
            {
                temp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
            }
            else
                i++;
        }
        
        for(i=0;i<n;i++)
           if(nums[i]!=i+1)
               return i+1;
        
        return n+1;
    }
};