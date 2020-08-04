/*
90. �Ӽ� II
����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: [1,2,2]
���:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/subsets-ii/
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
    vector<vector<int>> subsets��(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ret;
        vector<int> visited(nums.size(), 0);
        
        sort(nums.begin(), nums.end());
        dfs(nums, res, ret, visited, 0);
        
        return res;
    }
};