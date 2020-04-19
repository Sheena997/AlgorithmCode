/*
264. 丑数 II
编写一个程序，找出第 n 个丑数。
丑数就是只包含质因数 2, 3, 5 的正整数。
示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  
1 是丑数。
n 不超过1690。

来源：LeetCode
链接：https://leetcode-cn.com/problems/ugly-number-ii/
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int f2 = 0, f3 = 0, f5 = 0;
        for(int i = 1 ; i < n; ++i)
        {
            dp[i] = min(min(2 * dp[f2], 3 * dp[f3]), 5 * dp[f5]);
            if(dp[i] == 2 * dp[f2])
                ++f2;
            if(dp[i] == 3 * dp[f3])
                ++f3;
            if(dp[i] == 5 * dp[f5])
                ++f5;
        }
        
        return dp[n - 1];
    }
};


