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
    void dfs(vector<int>& candidates, vector<vector<int>>& solutions, vector<int>& solution, int preId, int curSum, int target)
    {
        if(curSum >= target)
        {
            if(curSum == target)
                solutions.push_back(solution);
            return;
        }
        //从后选中选择一个数字累加
        for(int i = preId; i < candidates.size(); ++i)
        {
            solution.push_back(candidates[i]);
            dfs(candidates, solutions, solution, i, curSum + candidates[i], target);
            
            //回溯
            solution.pop_back();
        }
            
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solutions;
        vector<int> solution;
        int curSum = 0;
        dfs(candidates, solutions, solution, 0, curSum, target);
        
        return solutions;
    }
};

     