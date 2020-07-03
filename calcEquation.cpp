/*
399. ������ֵ
��������ʽ A / B = k, ���� A �� B ��Ϊ���ַ�����ʾ�ı����� k ��һ�����������֡�������֪����ʽ������⣬
�����ؼ������������������ڣ��򷵻� -1.0��

ʾ�� :
���� a / b = 2.0, b / c = 3.0
����: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
���� [6.0, 0.5, -1.0, 1.0, -1.0 ]

����Ϊ: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries(����ʽ������ʽ��������ⷽ��ʽ)�� ���� equations.size() == values.size()��������ʽ�ĳ����뷽��ʽ���������ȣ���ʽ����һһ��Ӧ�������ҽ��ֵ��Ϊ����������Ϊ����ʽ�������� ����vector<double>���͡�

�����������ӣ��������£�

equations(����ʽ) = [ ["a", "b"], ["b", "c"] ],
values(����ʽ���) = [2.0, 3.0],
queries(���ⷽ��ʽ) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
����������Ч�ġ�����Լ�����������в�����ֳ���Ϊ0��������Ҳ������κ�ì�ܵĽ����

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/evaluate-division/
*/
class Solution {
public:
    bool dfs(unordered_map<string, vector<pair<string, double>>>& ump, vector<double>& res, string begin, string cur, double curr, unordered_set<string>& visited)
    {
        if(begin == cur)
        {
            res.push_back(curr);
            return true;
        }
        visited.insert(begin);
        for(auto x : ump[begin])
        {
            if(visited.count(x.first))
                continue;
            if(dfs(ump, res, x.first, cur, curr*x.second, visited))
                return true;
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> ump;
        vector<double> res;
        
        for(int i = 0; i < equations.size(); ++i)
        {
            ump[equations[i][0]].push_back(pair<string, double>(equations[i][1], values[i]));  // a / b
            ump[equations[i][1]].push_back(pair<string, double>(equations[i][0], 1 / values[i]));  // b / a
        }
        
        for(auto& e : queries)
        {
            if(e[0] == e[1])
            {
                if(ump.count(e[0]))
                    res.push_back(1.0);
                else
                    res.push_back(-1.0);
            }
            else
            {
                unordered_set<string> visited;
                visited.insert(e[0]);
                if(dfs(ump, res, e[0], e[1], 1.0, visited))
                    continue;
                else
                    res.push_back(-1.0);
            }
        }
        
        return res;
    }
};