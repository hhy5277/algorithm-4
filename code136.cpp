class Solution
{
private:
	map<char, int> m;
	std::vector<char> v;
public:
  //Insert one char from stringstream
    void Insert(char ch) {
    	++m[ch];
    	v.push_back(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
    	int n = v.size();

    	for (int i = 0; i < n; ++i) {
    		if (m[v[i]] == 1) {
    			return v[i];
    		}
    	}

    	return '#';
    }
};