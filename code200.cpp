class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmx(n,-1), rmx(n,-1);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l = max(l, height[i]);
            lmx[i] = l;
            r = max(r, height[n-1-i]);
            rmx[n-1-i] = r;
        }
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(lmx[i], rmx[i]) - height[i];
        }
        return water;
    }
};