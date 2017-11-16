/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
/*
思路：
解题思路：这道题的意思是一队小朋友排成行，
并且分出等级，每个小朋友至少要有一块糖，
且如果一个小朋友的等级高于左边或者右边的小朋友，
那它的糖就要比他们多。 求最少需要多少块糖可以满足这种要求。 
可以先给每个小朋友分一块糖，然后从前往后遍历一次，
确保每个人如果等级比前一个人高，那么所得的糖果数就是前一个人的基础上再加1个。 
但是这样还不能满足要求，因为有可能排在身后且等级更低的那一个人糖果数不少于自己。 
其实这种情况很容易就可以解决了，只要从后往前在遍历一次，类似从前往后遍历，
从后往前就要确保在排在前面一个而且等级更高的那个小朋友得到的糖果比当前这个位置的糖果数多1.
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> v(n, 1); // 保证每个人至少有一个糖果
        
        // 从前往后遍历，使得ratings比前面大的人糖果数比前面的人要多
        for (int i = 1; i < n; ++i) {
        	if ((ratings[i] > ratings[i - 1]) && (v[i] <= v[i - 1])) {
        		v[i] = v[i - 1] + 1;
        	}
        }

        // 从后往前遍历，使得ratings比后面大的人糖果数比后面的人要多
        for (int i = n - 2; i >= 0; --i) {
        	if ((ratings[i] > ratings[i + 1]) && (v[i] <= v[i + 1])) {
        		v[i] = v[i + 1] + 1;
        	}
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
        	sum += v[i];
        }

        return sum;
    }
};