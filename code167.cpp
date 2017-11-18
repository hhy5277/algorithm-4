/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
/*
思路：
使用二分查找。
一个小小的细节：在改变left或者right的时候，不要left = mid + 1，或者right = mid - 1。
因为这样的话，最后可能会出现left和right重合或者left在right后面的情况。
而使用left = mid或者right = mid，是一定存在right - left = 1的情况。
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
    	int n = rotateArray.size();
    	if (0 == n) {
    		return 0;
    	}

        int left, right, mid;
        left = 0; right = n - 1;
        mid = left;

        while (rotateArray[left] >= rotateArray[right]) {
        	mid = left + (right - left) / 2;

        	if (rotateArray[mid] >= rotateArray[0]) {
        		left = mid;
        	}
        	if (rotateArray[mid] <=rotateArray[n - 1]) {
        		right = mid;
        	}

        	if (right - left == 1) {
        		mid = right;
        		break;
        	}
        }

        return rotateArray[mid];
    }
};