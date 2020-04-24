/*
22. ��������
���� n �����������ŵĶ������������һ��������
�����ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�
ʾ����
���룺n = 3
�����[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
	 
��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/generate-parentheses/
*/
/*
������������һ����ʽ��������⣬������������ȱ�����Ҳ�����ù�����ȱ�����
һ����������ȱ�����
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