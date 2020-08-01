/*
46. 全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
通过次数162,761提交次数212,506

来源：LeetCode
链接：https://leetcode-cn.com/problems/permutations/
*/
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& ret, vector<int> nums, vector<int>& visited, int curIndex)
    {
        if(curIndex == nums.size())
        {
            res.push_back(ret);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                ret.push_back(nums[i]);
                dfs(res, ret, nums, visited, curIndex + 1);
                visited[i] = 0;
                ret.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ret;
        vector<int> visited(nums.size(), 0);
        
        dfs(res, ret, nums, visited, 0);
        
        return res;
    }
};