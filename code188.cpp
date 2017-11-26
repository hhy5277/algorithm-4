/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/
/*
思路：
使用第一行和第一列来标记哪些列和哪些行需要清零。
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        bool row0=false;//标记第一行是否存在0
        bool column0=false;//标记第一列是否存在0
        
        if(m==0||n==0)return;//特殊情况处理
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)column0=true;//第一列存在0
        }
        
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]==0)row0=true;//第一行存在0
        }
        
        for(int i=1;i<m;i++)//遍历除第一行和第一列以外的行列
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;//存储0元素出现的列下标
                    matrix[i][0]=0;//存储0元素出现的行下标
                }
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[0][j]==0||matrix[i][0]==0)//对应行列全部置零
                matrix[i][j]=0;
            }
        }
        if(row0==true)//如果第一行存在零，第一行置零
        {
            for(int i=0;i<n;i++)
            matrix[0][i]=0;
        }
        if(column0==true)//如果第一列原始存在0，则第一列置零
        {
            for(int i=0;i<m;i++)
            matrix[i][0]=0;
        }
    }
};