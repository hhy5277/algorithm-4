class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        return combine(n, k, 1);
    }
    
    vector<vector<int> > combine(int n, int k, int start) {
        vector<vector<int> > ret;
        if (k == 1) {
            for (int i = start; i <= n; i++) {
                vector<int> one;
                one.push_back(i);
                ret.push_back(one);
            }
            return ret;
        } else if (n < k || n-start+1 < k) { return ret; }
        
        vector<vector<int> > left1 = combine(n, k-1, start+1);
        for (int i = 0; i < left1.size(); i++) {
            left1[i].push_back(start);
            ret.push_back(left1[i]);
        }
        vector<vector<int> > left2 = combine(n, k, start+1);
        for (int i = 0; i < left2.size(); i++) { ret.push_back(left2[i]);}
        return ret;
    }
};