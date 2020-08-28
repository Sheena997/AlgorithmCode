/*
面试题 01.05. 一次编辑
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换
一个字符。 给定两个字符串，编写一个函数判定它们是否只需
要一次(或者零次)编辑。 

示例 1:
输入: 
first = "pale"
second = "ple"
输出: True

示例 2:
输入: 
first = "pales"
second = "pal"
输出: False

来源：LeetCode
链接：https://leetcode-cn.com/problems/one-away-lcci/
*/
class Solution {
public:
    bool oneEditAway(string first, string second) {
        vector<vector<int>> dp(first.size() + 1, vector<int>(second.size() + 1));
        for(int i = 1; i < first.size() + 1; ++i)
            dp[i][0] = i;
        for(int j = 1; j < second.size() + 1; ++j)
            dp[0][j] = j;
        
        for(int i = 1; i < first.size() + 1; ++i)
        {
            for(int j = 1; j < second.size() + 1; ++j)
            {
                if(first[i - 1] == second[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        
        if(dp[first.size()][second.size()] > 1)
            return false;
        
        return true;
    }
};