/*
454. ������� II
�����ĸ����������������б� A , B , C , D ,�����ж��ٸ�Ԫ�� (i, j, k, l) ��
ʹ�� A[i] + B[j] + C[k] + D[l] = 0��

Ϊ��ʹ����򵥻������е� A, B, C, D ������ͬ�ĳ��� N���� 0 �� N �� 500 ��
���������ķ�Χ�� -228 �� 228 - 1 ֮�䣬���ս�����ᳬ�� 231 - 1 ��

����:

����:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

���:
2

����:
����Ԫ������:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/4sum-ii/
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> ab;
        unordered_map<int, int> cd;
        for(int x : A)
        {
            for(int y : B)
                ++ab[x + y];
        }
        
        for(int x : C)
        {
            for(int y : D)
                ++cd[x + y];
        }
        
        for(auto e : ab)
        {
            int ret = (-e.first);
            if(cd.find(ret) != cd.end())
                res += (e.second * cd[ret]);
        }
        
        return res;
    }
};



class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> unmp;
        for(int x : A)
        {
            for(int y : B)
            {
                if(unmp.find(x + y) != unmp.end())
                    ++unmp[x + y];
                else
                    unmp[x + y] = 1;
            }
        }
        
        for(int x : C)
        {
            for(int y : D)
            {
                if(unmp.find(0- (x + y)) != unmp.end())
                    res += unmp[0 - (x + y)];
            }
        }
        
        return res;
    }
};