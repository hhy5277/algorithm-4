/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
给定一个数n，求1到n这些数可以构成多少棵二叉树。
*/
/*
思路：
给定一个序列1.....n，为了构造所有二叉树，我们可以使用1......n中的每一个数i作为根节点，自然1......(i-1)必然位于树的左子树中，(i+1).....n位于树的右子树中。然后可以递归来构建左右子树，由于根节点是唯一的，所以可以保证构建的二叉树都是唯一的。

使用两个状态来记录：

G(n)：长度为n的序列的所有唯一的二叉树。

F(i,n)，1<=i<=n：以i作为根节点的二叉树的数量。

G(n)就是我们要求解的答案，G(n)可以由F(i,n)计算而来。

G(n)=F(1,n)+F(2,n)+...+F(n,n)                      (1)

G(0)=1,G(1)=1

对于给定的一个序列1.....n，我们取i作为它的根节点，那么以i作为根节点的二叉树的数量F(i)可以由下面的公式计算而来：

F(i,n)=G(i-1)*G(n-i) 1<=i<=n                         (2)
其中的 G(i-1) 代表根节点i的左子树有多少种情况，G(n-i) 代表根节点i的右子树有多少种情况

综合公式（1）和公式（2），可以看出：

G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)

这就是上面这个问题的答案。
*/
class Solution {
public:
    int numTrees(int n) {
        int *G=new int[n+1]();
        G[0] = 1;
        G[1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < i; ++j)
                G[i] += G[j] * G[i - j - 1];
        }

        return G[n];  
    }
};