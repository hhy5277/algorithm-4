/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> v3;

        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(v3));

        vector<int>::iterator iter = unique(v3.begin(), v3.end());
        v3.erase(iter,v3.end()); // 删除后面的那些重复元素

        return v3;
    }
};
