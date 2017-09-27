/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

思路：
题目叫做Ransom Note，勒索信，刚开始我还没理解这个题目的意思，
尤其这个标题，和magazine有啥关系呢？后来仔细想想，才慢慢理解。
勒索信，为了不暴露字迹，就从杂志上搜索各个需要的字母，组成单词来表达的意思。
这样来说，题目也就清晰了，判断杂志上的字是否能够组成勒索信需要的那些字符。 
这里需要注意的就是杂志上的字符只能被使用一次，不过不用考虑大小写的问题。 
有一种最简单的理解就是对于ransomNote里每个字符出现的次数必须小于或者等于该字符在magazine出现的次数。

注意：magazine中的字符只能用一次。


*/
class Solution {  
public:  
    bool canConstruct(string ransomNote, string magazine) {  
        vector<int> hash(26, 0); 

        for(auto c:magazine) ++hash[c-'a'];  
        for(auto c:ransomNote) {  
            if(--hash[c-'a'] < 0) return false;  
        }  

        return true;  
    }  
}; 