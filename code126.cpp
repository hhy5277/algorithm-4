/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	int n = sequence.size();
        if (0 == n) {
        	return false;
        }

        return __VerifySquenceOfBST(sequence, 0, n - 1);
    }

    bool __VerifySquenceOfBST(vector<int>& sequence, int l, int r) {
    	if (l > r) {
    		return true;
    	}

        int root = sequence[r];

        int i = 0;
        for (; i < r; ++i) {
        	if (sequence[i] > root) {
        		break;
        	}
        }

        int j = i + 1;
        for (; j < r; ++j) {
        	if (sequence[j] < root) {
        		return false;
        	}
        }

        return __VerifySquenceOfBST(sequence, l, i - 1) && __VerifySquenceOfBST(sequence, i, r - 1);
    }
};