/*
51. N�ʺ�
n �ʺ������о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������

����һ������ n���������в�ͬ�� n �ʺ�����Ľ��������

ÿһ�ֽⷨ����һ����ȷ�� n �ʺ���������ӷ��÷�����
�÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ��

ʾ��:
����: 4
���: [
 [".Q..",  // �ⷨ 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // �ⷨ 2
  "Q...",
  "...Q",
  ".Q.."]
]
����: 4 �ʺ��������������ͬ�Ľⷨ��
 

��ʾ��
�ʺ��ǹ��������е����ӣ���ζ�Ź��������ӡ��ʺ�ֻ��һ���£�
�Ǿ��ǡ����ӡ��������������ԳԵ�����ʱ����Ѹ�ٳ���ȥ�Ե����ӡ�
��Ȼ�����ᡢ����б������һ���߲����ɽ����ˡ��������� �ٶȰٿ� - �ʺ� ��
*/
class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& solutions, vector<pair<int, int>>& solution, int curRow, int n)
    {
        //��ÿһ�е�λ�ö�ȷ��֮�󣬱��淽��
        if(n == curRow)
        {
            solutions.push_back(solution);
            return;
        }
        
        //���ڵ�ǰ�б���ÿһ�п��ܵ�λ��
        for(int i = 0; i < n; ++i)
        {
            if(isValid(solution, curRow, i))
            {
                //���浱ǰ�ʺ��λ��
                solution.push_back(make_pair(curRow, i));
            
                //ȷ����һ�еĻʺ��λ��
                dfs(solutions, solution, curRow + 1, n);
            
                //������һ�е�λ�ã�����
                solution.pop_back();
            }
        }
    }
    
    bool isValid(vector<pair<int, int>>& solution, int row, int col)
    {
        //��֤��ÿһ���ʺ��λ�ö�����ͻ
        for(pair<int, int> pos : solution)
        {
            //����ͬһ���Ҳ���ͬһб����
            if(pos.second == col
              || pos.first + pos.second == row + col
              || pos.first - pos.second == row - col)
                return false;
        }
        
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int, int>>> solutions;
        vector<pair<int, int>> solution;
        
        dfs(solutions, solution, 0, n);
        
        return trans(solutions, n);
    }
    
    vector<vector<string>> trans(vector<vector<pair<int, int>>>& solutions, int n)
    {
        vector<vector<string>> res;
        //ת��ÿһ������
        for(vector<pair<int, int>> s : solutions)
        {
            vector<string> vs(n, string(n, '.'));//n��n����.��
            for(pair<int, int> pos : s)
            {
                //�ʺ��λ�ø�ֵΪ'Q'
                vs[pos.first][pos.second] = 'Q';
            }
            //ת���õ�һ�ַ���
            res.push_back(vs);
        }
        
        return res;
    }
};