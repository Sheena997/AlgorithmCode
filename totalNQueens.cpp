/*
52. N�ʺ� II
n �ʺ������о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
ʾ��:
����: 4
���: 2
����: 4 �ʺ������������������ͬ�Ľⷨ��
[
 [".Q..",  // �ⷨ 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // �ⷨ 2
  "Q...",
  "...Q",
  ".Q.."]
]
 

��ʾ��
�ʺ��ǹ��������е����ӣ���ζ�Ź��������ӡ��ʺ�ֻ��һ���£�
�Ǿ��ǡ����ӡ��������������ԳԵ�����ʱ����Ѹ�ٳ���ȥ�Ե����ӡ�
��Ȼ�����ᡢ����б������һ���߲����ɽ����ˡ��������� �ٶȰٿ� - �ʺ� ��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/n-queens-ii/
*/
class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& res, vector<pair<int, int>>& vs, int n, int curRow)
    {
        if(curRow >= n)
        {
            if(curRow == n)
                res.push_back(vs);
            return;
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(isValid(vs, curRow, i))
            {
                vs.push_back(make_pair(curRow, i));
                dfs(res, vs, n, curRow + 1);
                vs.pop_back();
            }
        }
    }
    bool isValid(vector<pair<int, int>>& vs, int row, int col)
    {
        for(pair<int, int> e : vs)
        {
            if(e.second == col
              || e.first + e.second == row + col
              || e.first - e.second == row - col)
                return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        vector<vector<pair<int, int>>> res;
        vector<pair<int, int>> vs;
        
        dfs(res, vs, n, 0);
        
        return res.size();
    }
};