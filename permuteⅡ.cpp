/*
47. ȫ���� II
����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�

ʾ��:

����: [1,1,2]
���:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/permutations-ii/
*/
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& ret, vector<int>& visited, vector<int> nums, int curIndex)
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
                if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 1)
                    continue;
            
                ret.push_back(nums[i]);
                visited[i] = 1;
                dfs(res, ret, visited, nums, curIndex + 1);
                visited[i] = 0;
                ret.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ret;
        vector<int> visited(nums.size(), 0);

        sort(nums.begin(), nums.end());
        
        dfs(res, ret, visited, nums, 0);
        
        return res;
    }
};