/*
216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。
组合中只允许含有 1 - 9 的正整数，并且
每种组合中不存在重复的数字。
说明：
所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

来源：LeetCode
链接：https://leetcode-cn.com/problems/combination-sum-iii/
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    
    void dfs(int k, int n, int sum, int i)
    {
        if(sum == n && tmp.size() == k)
            res.push_back(tmp);
        
        for(int j = i; j <= 9; ++j)
        {
            if(sum < n)
            {
                tmp.push_back(j);
                dfs(k, n, sum + j, j + 1);
                tmp.pop_back();
            }
            else if(sum > n)
            {
                break;
            }
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 0, 1);
        
        return res;
    }
};