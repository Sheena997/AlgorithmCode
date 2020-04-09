/*
39. 组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

来源：LeetCode
链接：https://leetcode-cn.com/problems/combination-sum/
*/
/*
解题思路
每次有两种选择：
要不就不选当前
要不就选择一直选择当前元素
若遇到元素当前元素已经大于target的情况则剪枝
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void dfs(vector<int>& candidates, int target, int pos)
    {
        if(target == 0)
        {
            res.push_back(path);
            return;
        }
        
        if(target < 0)//剪枝
            return;
        if(pos == candidates.size())
            return;
        
        // 可以重复选当前
        path.push_back(candidates[pos]);
        dfs(candidates, target - candidates[pos], pos);
        path.pop_back();
        
        //不选当前选下一个
        dfs(candidates, target, pos + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        
        return res;
    }
};

     