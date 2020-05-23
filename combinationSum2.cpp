/*
40. ����ܺ� II
����һ������ candidates ��һ��Ŀ���� target ��
�ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�

˵����

�������֣�����Ŀ������������������
�⼯���ܰ����ظ�����ϡ� 
ʾ�� 1:

����: candidates = [10,1,2,7,6,1,5], target = 8,
����⼯Ϊ:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
ʾ�� 2:

����: candidates = [2,5,2,1,2], target = 5,
����⼯Ϊ:
[
  [1,2,2],
  [5]
]

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/combination-sum-ii/
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