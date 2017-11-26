/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
/*
思路：
因为涉及到回退，所以想到用栈这个数据结构达到回退的目的。
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStack;
        
        stringstream ss(path);
        string t;
        while(getline(ss, t, '/')) {
            if(t.empty() || t == ".") continue;
            else if(t == "..") {
                if(!pathStack.empty()) pathStack.pop();
            } else {
                pathStack.push(t);
            }
        }
        
        string res;
        
        while(!pathStack.empty()) {
            res.insert(0, pathStack.top());
            pathStack.pop();
            res.insert(0, "/");
        }
            
        return res.empty() ? "/" : res;
    }
};