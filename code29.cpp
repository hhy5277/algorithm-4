/*
Suppose Andy and Doris want to choose a restaurant for dinner, 
and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. 
If there is a choice tie between answers, output all of them with no order requirement. 
You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
*/

/*
思路：
把索引和可能是最小的那些餐馆都放入哈希表里面，最后输出那个索引和真正最小的餐馆
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> um;
        unordered_map<int, vector<string> > interest_map;
        int list1_nums = list1.size();
        int list2_nums = list2.size();

        int min_sum = 10000;

        for (int i = 0; i < list1_nums; i++) {
            um[list1[i]] = i;
        }

        for (int i = 0; i < list2_nums; i++) {
        	if (um.count(list2[i])) {
        		if (min_sum>= i + um[list2[i]]) {
        			min_sum = i + um[list2[i]];
        		    interest_map[min_sum].push_back(list2[i]);
        		}
        	}
        }

        return interest_map[min_sum];
    }
};