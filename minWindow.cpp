/*
76. ��С�����Ӵ�
����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���

ʾ����

����: S = "ADOBECODEBANC", T = "ABC"
���: "BANC"
˵����

��� S �в����������Ӵ����򷵻ؿ��ַ��� ""��
��� S �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/minimum-window-substring/
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, need;
        int len = INT_MAX, left = 0, right = 0, start = 0, match = 0;
        
        for(auto& e : t)
            ++need[e];
        
        while(right < s.size())
        {
            char c1 = s[right];
            if(need.count(c1))
            {
                ++window[c1];
                if(need[c1] == window[c1])
                    ++match;
            }
            ++right;
            
            while(need.size() == match)
            {
                char c2 = s[left];
                if(right - left < len)
                {
                    len = right - left;
                    start = left;
                }
                if(need.count(c2))
                {
                    if(window[c2] == need[c2])
                        --match;
                    --window[c2];
                }
                ++left;
            }
        }
        
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};



