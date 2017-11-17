/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int dis=1;
        int len=wordList.size();
        int *visit=new int[len];
        memset(visit,0,len*sizeof(int));

        queue<string> q; // 用来存放目前已经到达的节点（并且，这些节点可能是并列的）
        for (int i=0; i<len; i++)
        {
            if (cmpStr(beginWord, wordList[i])==true)
            {
                if (wordList[i] == endWord) return 2;
                q.push(wordList[i]);
                visit[i]=1; // 代表已经访问了这个节点。其中，i与wordList中的索引相对应
            }

        }
        if (q.empty()) return 0;
        dis++;

        while (!q.empty())
        {
            int _siz=q.size();
            while (_siz)
            {
                string tmp(q.front());
                if (tmp == endWord) return dis;
                for (int i=0; i<len; i++)
                {
                    if (!visit[i]) // 如果这个节点没有到达过
                    {
                        if (cmpStr(tmp, wordList[i])) // 并且这个节点与目前到达的节点相邻
                        {
                            if (wordList[i] == endWord) return dis+1; // 如果这个节点刚好是最终的目标，那么就可以返回结果了
                            q.push(wordList[i]); // 并且从q.front()节点往后走一步，到达这个节点
                            visit[i]=1; // 把这个节点标记为已经访问了
                        }
                    }
                    // 注意，虽然可能已经找到了下一个节点，但是，我们并没有立即结束循环，而是继续去寻找与tmp相邻的节点。因为可能有更短的路径
                }
                q.pop();
                _siz--;
            }
            dis++;
        }
        return 0;
    }
    
    /*
    作用：判断字符串s1和字符串s2是否只有一个字符不同
    参数1：字符串s1
    参数2：字符串s2
    */
    bool cmpStr(string s1, string s2)
    {
        int len=s1.size();
        int diff=0; // 记录s1和s2有几个字符不同
        for (int i=0; i<len; i++)
        {
            if (s1[i] != s2[i])
            {
                diff++;
            }
        }
        if (diff == 1) return true;
        else return false;
    }
};