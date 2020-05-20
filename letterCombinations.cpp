/*
17. �绰�������ĸ���
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
ʾ��:
���룺"23"
�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
˵��:
��������Ĵ��ǰ��ֵ������еģ��������������ѡ��������˳��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
*/
string strMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    void dfs(string digits, vector<string>& res, int curId, string curStr)
    {
        //�߽�����
        if(curId == digits.size())
        {
            if(!curStr.empty())
                res.push_back(curStr);
            return;
        }
        //�ӵ�ǰλ�õ�����ӳ����ѡ��һ���ַ�������ƴ��
        string curMap = strMap[digits[curId] - '0'];
        for(char ch : curMap)
            dfs(digits, res, curId + 1, curStr + ch);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        dfs(digits, res, 0, "");
        
        return res;
    }
};