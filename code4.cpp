/*
设置两个变量up和rignt，用来记录位移
向右移动right加一，向左移动减一
向上移动up加一，向下移动减一
*/
class Solution {
public:
    bool judgeCircle(string moves) {
        int right = 0, up = 0;
        for (int i = 0; i < moves.length(); i++) {
        	if (moves[i] == 'L') {
        		right--;
        	}
        	if (moves[i] == 'R') {
        		right++;
        	}
        	if (moves[i] == 'U') {
        		up++;
        	}
        	if (moves[i] == 'D') {
        		up--;
        	}
        }

        if (right == 0 && up == 0) {
        	return true;
        }
        else {
        	return false;
        }
    }
};