/*
40. 组合总和 II
给定一个数组 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

来源：LeetCode
链接：https://leetcode-cn.com/problems/combination-sum-ii/
*/
class Solution {
public:
    void dfs(vector<int> candidates, int target, vector<int>& ret, vector<vector<int>>& res, int curSum, int preId)
    {
        if(curSum >= target)
        {
            if(curSum == target)
                res.push_back(ret);
            return;
        }
        
        for(int i = preId; i < candidates.size(); ++i)
        {
            if(i > preId && candidates[i] == candidates[i - 1])
                continue;
            ret.push_back(candidates[i]);
            
            dfs(candidates, target, ret, res, curSum + candidates[i], i + 1);
            
            ret.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ret;
        int curSum = 0;
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, target, ret, res, curSum, 0);
        
        return res;
    }
};