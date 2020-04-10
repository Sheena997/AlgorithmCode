/*
77. 组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
示例:
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：LeetCode
链接：https://leetcode-cn.com/problems/combinations/
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    
    void dfs(int n, int k, int i)
    {
        if(k == 0)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int j = i; j <= n; ++j)
        {
            tmp.push_back(j);
            dfs(n, k - 1, j + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        
        return res;
    }
};