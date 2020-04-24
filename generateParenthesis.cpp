/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，
用于能够生成所有可能的并且 有效的 括号组合。
示例：
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
	 
来源：LeetCode
链接：https://leetcode-cn.com/problems/generate-parentheses/
*/
/*
这类问题是在一棵隐式的树上求解，可以用深度优先遍历，也可以用广度优先遍历，
一般用深度优先遍历。
*/
class Solution {
public:
    vector<string> res;
    string ret;
    vector<string> generateParenthesis(int n) {
        dfs(ret, 0, 0, n);
        
        return res;
    }
    void dfs(string ret, int l, int r, int n)
    {
        if(l > n || r > n || r > l || r < 0)
            return;
        
        if(l == n && r == n)
        {
            res.push_back(ret);
            return;
        }
        
        dfs(ret + '(', l + 1, r, n);
        dfs(ret + ')', l, r + 1, n);
        
        return;
    }
};