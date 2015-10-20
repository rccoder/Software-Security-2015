Lab1 * 求所有的最长公共子序列
===

## 实验方法：
在普通的LCS问题上做一些拓展，当c[i][j-1]和c[i-1][j]相等的时候添加一种状态，最后采用set去重。

## 已知问题
由于不是对路径做标记，去重是建立在最后得到的子串的基础上的。会浪费多余的空间，并且不能求出 “看似相等，实则不在同一个位置” 的子串。