/*
90. 子集 II
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：LeetCode
链接：https://leetcode-cn.com/problems/subsets-ii/
*/
class Solution {
public:
    void dfs(vector<int> nums, vector<vector<int>>& res, vector<int>& ret, vector<int>& visited, int index)
    {
        res.push_back(ret);
        
        for(int i = index; i < nums.size(); ++i)
        {
            if(i - 1 >= 0 && nums[i - 1] == nums[i] && visited[i - 1] == 0)
            {
                continue;
            }
            else
            {
                ret.push_back(nums[i]);
                visited[i] = 1;
                dfs(nums, res, ret, visited, i + 1);
                visited[i] = 0;
                ret.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsⅡ(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ret;
        vector<int> visited(nums.size(), 0);
        
        sort(nums.begin(), nums.end());
        dfs(nums, res, ret, visited, 0);
        
        return res;
    }
};