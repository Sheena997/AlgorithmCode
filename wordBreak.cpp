/*
题目描述
给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列，
使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
例如:
给定s=“leetcode”；
dict=["leet", "code"].
返回true，因为"leetcode"可以被分割成"leet code".

Given a string s and a dictionary of words dict, determine if s can be 
segmented into a space-separated sequence of one or more dictionary words.
For example, given

s ="leetcode",
dict =["leet", "code"].

Return true because"leetcode"can be segmented as"leet code".

来源：牛客网
链接：https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty())
            return false;
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;
        for(int i = 1; i < s.size() + 1; ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};