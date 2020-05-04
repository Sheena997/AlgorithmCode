/*
面试题 08.04. 幂集
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

说明：解集不能包含重复的子集。

示例:

 输入： nums = [1,2,3]
 输出：
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
链接：https://leetcode-cn.com/problems/power-set-lcci/
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> ret;
    void _subsets(vector<int>&nums, int n)
    {
        if(n == nums.size())
            return;
        for(int i = n; i < nums.size(); ++i)
        {
            ret.push_back(nums[i]);
            res.push_back(ret);
            _subsets(nums, i + 1);
            ret.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(ret);
        _subsets(nums, 0);
        
        return res;
    }
};
