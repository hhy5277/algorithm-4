class Solution {
public:
    int jumpFloorII(int number) {
        int res[number + 1];
        res[0] = 1;
        res[1] = 1;
        res[2] = 2;

        for (int i = 3; i <= number; ++i) {
        	res[i] = 0;
        	for (int j = i - 1; j >= 0; --j ) {
        		res[i] += res[j];
        	}
        }

        return res[number];
    }
};