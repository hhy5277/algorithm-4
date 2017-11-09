/*
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，
则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 
即输出P%1000000007
*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        int n = data.size();

        int res = (int)__InversePairs(data, 0, n - 1);

        return res;
    }

    long long __InversePairs(vector<int>& data, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;

        long long left_count = __InversePairs(data, l, mid);
        long long right_count = __InversePairs(data, mid + 1, r);

        return (left_count + right_count + merge(data, l, mid, r)) % 1000000007;
    }

    int merge(vector<int>& data, int l, int mid, int r) {
        int length = r - l + 1; // 数组中元素的个数
        vector<int> temp(length);

        int i = mid, j = r, n = length - 1;
        long long count = 0;

        while (i >= l && j >= mid + 1) {
            if (data[i] > data[j]) {
                temp[n--] = data[i--];
                count += j - mid;
                count %= 1000000007;
            }
            else {
                temp[n--] = data[j--];
            }
        }

        for (; i >= l; --i) {
            temp[n--] = data[i];
        }
        for (; j >= mid + 1; --j) {
            temp[n--] = data[j];
        }
        
        n = 0;
        for (int k = l; k <= r; ++k) {
            data[k] = temp[n++];
        }

        return count;
    }
};