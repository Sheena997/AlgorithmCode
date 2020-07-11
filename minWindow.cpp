/*
76. 最小覆盖子串
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

来源：LeetCode
链接：https://leetcode-cn.com/problems/minimum-window-substring/
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



