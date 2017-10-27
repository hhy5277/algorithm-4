/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, 
the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/
/*
思路：
先对整个数组进行翻转，
再对[0, k-1]位置的数字进行反转，再对剩下的[k, n - 1]部分进行翻转。 
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n = nums.size();
         k = k % n;

         for (int i = 0, j = n - 1; i < j; ++i, --j) {
         	swap(nums[i], nums[j]);
         }

         for (int i = 0, j = k - 1; i < j; ++i, --j) {
         	swap(nums[i], nums[j]);
         }

         for (int i = k, j = n - 1; i < j; ++i, --j) {
         	swap(nums[i], nums[j]);
         }
    }
};