/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > vv;
        std::vector<int> temp_v;
        if (numRows == 0) {
        	return vv;
        }

        temp_v.push_back(1);
        vv.push_back(temp_v);

        for (int i = 1; i <numRows; i++) {
        	std::vector<int> v;
        	for (int j = 0; j < i + 1; j++) {
        		if (j == 0) {
                    v.push_back(1);
        		}
        		else if ((j == i)){
        			v.push_back(1);
        		}
        		else {
        			v.push_back(vv[i - 1][j - 1] + vv[i - 1][j]);
        		}
        	}

        	vv.push_back(v);
        }

        return vv;
    }
};