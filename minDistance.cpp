/*
动态规划 leetcode
题目描述
给定两个单词word1和word2，请计算将word1转换为word2至少需要多少步操作。
你可以对一个单词执行以下3种操作：
a）在单词中插入一个字符
b）删除单词中的一个字符
c）替换单词中的一个字符

Given two words word1 and word2, find the minimum number of 
steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

来源：牛客网
链接：https://www.nowcoder.com/practice/81d7738f954242e5ade5e65ec40e5027?tpId=46&tqId=29106&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        //初始化
        //F(i, 0) = i
        //F(0, j) = j
        for(int i = 0; i < len1 + 1; ++i)
            dp[i][0] = i;
        for(int j = 0; j < len2 + 1; ++j)
            dp[0][j] = j;
        
        //递推
        for(int i = 1; i < len1 + 1; ++i)
        {
            for(int j = 1; j < len2 + 1; ++j)
            {
                //插入、删除中找到最小的
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                //替换
                dp[i][j] = min(dp[i][j], (word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1));
            }
        }
        
        return dp[len1][len2];
    }
};