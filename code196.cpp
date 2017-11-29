/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
思路：
注意先对数组进行排序
*/
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> v;
        int n = intervals.size();

        if (0 == n) {
        	return v;
        }
        if (1 == n) {
        	v.push_back(intervals[0]);
        	return v;
        }

        sort(intervals.begin(),intervals.end(),  compare_Interval); 

        Interval temp = intervals[0];
        int i = 1;

        while (i < n) {
        	if (temp.end < intervals[i].start) {
        		v.push_back(temp);
        		temp = intervals[i];
        		++i;
        		if (i == n) {
        			v.push_back(temp);
        		}
        	}
        	else {
        		temp.start = min(temp.start, intervals[i].start);
        		temp.end = max(temp.end, intervals[i].end);
        	    ++i;

        	    if (i == n) {
        	    	v.push_back(temp);
        	    }
        	}
        }

        return v;
    }

    static int compare_Interval(Interval val1, Interval val2){  
        return val1.start < val2.start;  
    }
};