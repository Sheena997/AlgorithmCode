/*
78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：LeetCode
链接：https://leetcode-cn.com/problems/subsets/
*/
class Solution {
public:
    void dfs(vector<int> nums, vector<vector<int>>& res, vector<int>& ret, int index)
    {
        res.push_back(ret);
        
        for(int i = index; i < nums.size(); ++i)
        {
            ret.push_back(nums[i]);
            dfs(nums, res, ret, i + 1);
            ret.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ret;
        
        dfs(nums, res, ret, 0);
        
        return res;
    }
};