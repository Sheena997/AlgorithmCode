/*
题目描述
给定一个字符串S和一个字符串T，计算S中的T的不同子序列的个数。
字符串的子序列是由原来的字符串删除一些字符（也可以不删除）
在不改变相对位置的情况下的剩余字符（例如，"ACE"is a subsequence of"ABCDE"但是"AEC"不是）
例如：
S ="rabbbit", T ="rabbit"
返回3

来源：牛客网
链接：https://www.nowcoder.com/practice/ed2923e49d3d495f8321aa46ade9f873?tpId=46&tqId=29065&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int row = S.size(), col = T.size();
        if(col == 0)
            return 1;
        if(row == 0)
            return 0;
        
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        
        //初始化
        for(int i = 0; i < row + 1; ++i)
            dp[i][0] = 1;
        
        //递推
        for(int i = 1; i < row + 1; ++i)
        {
            for(int j = 1; j < col + 1; ++j)
            {
                /*
                if(S[i - 1] == T[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
                 */
                dp[i][j] = dp[i - 1][j] + (S[i -1] == T[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        
        return dp[row][col];
    }
};