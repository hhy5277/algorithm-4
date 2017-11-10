/*
题目描述
统计一个数字在排序数组中出现的次数。
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
    	int n = data.size();
        if (n == 0) {
        	return 0;
        }

        int first = GetFirstK(data, 0, n - 1, k);   
        int second = GetSecondK(data, first, n - 1, k);

        if (first == -1) {
        	return 0;
        }
        else {
            return second - first + 1;
        }
    }

    int GetFirstK(vector<int>& data, int l, int r, int k) {
    	while (l <= r) {
    		int mid = l + (r - l) / 2;

    		if ((data[mid] == k) && (data[mid - 1] == k)) {
    			r = mid - 1;
    		}
    		if ((data[mid] == k) && (data[mid - 1] != k)) {
    			return mid;
    		}
    		if (data[mid] < k) {
    			l = mid + 1;
    		}
    		if (data[mid] > k) {
    			r = mid - 1;
    		}
    	}

    	return -1;
    }

    int GetSecondK(vector<int>& data, int l, int r, int k) {
    	while (l <= r) {
    		int mid = l + (r - l) / 2;

    		if ((data[mid] == k) && (data[mid + 1] == k)) {
    			l = mid + 1;
    		}
    		if ((data[mid] == k) && (data[mid + 1] != k)) {
    			return mid;
    		}
    		if (data[mid] < k) {
    			l = mid + 1;
    		}
    		if (data[mid] > k) {
    			r = mid - 1;
    		}
    	}

    	return -1;
    }
};