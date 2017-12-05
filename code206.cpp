
class Solution {
public:
    int divide(int dividend, int divisor) {
    	bool is_positive_num = true;
    	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
    		is_positive_num = false;
    	}
    	long divend = abs((long)dividend);
    	long divor = abs((long)divisor);
    	if (divend < divor) {
    		return 0;
    	}

    	long temp = divor;

        long sum = 0;
        long num = 0;

        while (sum < divend) {
        	if (sum + temp > divend) {
        		if (divend - sum < divor) {
        			if (is_positive_num) {
        				return num;
        			}
        			else {
            			return -num;
        			}
        		}
        		else {
                    temp = divor;
        		}
        	}
        	sum += temp;
        	num += (temp / divor);
        	temp = (temp << 1);

        	if (sum == divend) {
        		if (is_positive_num) {
        			if (num > INT_MAX) {
        				return INT_MAX;
        			}
        			else {
        			    return num;
        			}
        		}
        		else {
        			return -num;
        		}
        	}
        }
    }
};