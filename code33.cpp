/*
Given two arrays, 
write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], 
return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
*/
/*
思路：
因为我们采用一步一步挪动两个下标的方法来比较元素的值，
所以我们需要对两个数组进行排序
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        
        std::vector<int> v;

        for (int i = 0, j = 0; i < nums1_size && j < nums2_size;) {
            if (nums1[i] == nums2[j]) {
            	v.push_back(nums1[i]);
            	i++;
            	j++;
            }
            else if (nums1[i] < nums2[j]) {
            	i++;
            }
            else {
            	j++;
            }
        }

        return v;
    }
};