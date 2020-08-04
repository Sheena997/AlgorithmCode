/*
78. �Ӽ�
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: nums = [1,2,3]
���:
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

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/subsets/
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