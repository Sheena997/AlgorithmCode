/*
��Ŀ����
����һ���ַ���s��һ�鵥��dict���ж�s�Ƿ�����ÿո�ָ��һ���������У�
ʹ�õ������������еĵ��ʶ���dict�еĵ��ʣ����п��԰���һ���������ʣ���
����:
����s=��leetcode����
dict=["leet", "code"].
����true����Ϊ"leetcode"���Ա��ָ��"leet code".

Given a string s and a dictionary of words dict, determine if s can be 
segmented into a space-separated sequence of one or more dictionary words.
For example, given

s ="leetcode",
dict =["leet", "code"].

Return true because"leetcode"can be segmented as"leet code".

��Դ��ţ����
���ӣ�https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
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