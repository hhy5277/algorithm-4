class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len = digits.size();

        if (0 == len) {
        	return res;
        }

        map<char, string> m;

        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        char c1 = digits[0];
        char c2 = digits[1];
        string s1 = m[c1];
        string s2 = m[c2];
        string part = "";

        __letterCombinations(res, s1, 0, s2, 0, part);

        return res;
    }

    void __letterCombinations(vector<string> &res, string s1, int i1, string s2, int i2, string part) {
    	part += s1[i1];
    	part += s2[i2];

    	res.push_back(part);

    	part = "";

    	int len1 = s1.size(); // len = 3   index = 0 1 2
    	int len2 = s2.size();

    	if (i1 >= len1 - 1 && i2 >= len2 - 1) {
    		return;
    	}
        
        if (i2 >= len2 - 1) {
            i1++;
    		i2 = -1;
        }
    	__letterCombinations(res, s1, i1, s2, i2 + 1, part);
    }
};


// 上面的解法只适用于输入了两个数字的情况

// 正确解法
/*
枚举所有情况。

对于每一个输入数字，对于已有的排列中每一个字符串，分别加入该数字所代表的每一个字符。

所有是三重for循环。

举例：

初始化排列{""}

1、输入2，代表"abc"

已有排列中只有字符串""，所以得到{"a","b","c"}

2、输入3，代表"def"

(1)对于排列中的首元素"a"，删除"a"，并分别加入'd','e','f'，得到{"b","c","ad","ae","af"}

(2)对于排列中的首元素"b"，删除"b"，并分别加入'd','e','f'，得到{"c","ad","ae","af","bd","be","bf"}

(2)对于排列中的首元素"c"，删除"c"，并分别加入'd','e','f'，得到{"ad","ae","af","bd","be","bf","cd","ce","cf"}

注意

（1）每次添加新字母时，应该先取出现有ret当前的size()，而不是每次都在循环中调用ret.size()，因为ret.size()是不断增长的。

（2）删除vector首元素代码为：

ret.erase(ret.begin());
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits == "")
            return ret;
            
        ret.push_back("");
        
        vector<string> dict(10); //0~9
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        
        for(int i = 0; i < digits.size(); i ++)
        {
            int size = ret.size();
            for(int j = 0; j < size; j ++)
            {
                string cur = ret[0];
                ret.erase(ret.begin());
                for(int k = 0; k < dict[digits[i]-'0'].size(); k ++)
                {
                    ret.push_back(cur + dict[digits[i]-'0'][k]);
                }
            }
        }
        return ret;
    }
};
