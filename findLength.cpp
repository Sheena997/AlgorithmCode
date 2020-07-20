/*
718. ��ظ�������
�������������� A �� B ���������������й����ġ��������������ĳ��ȡ�

ʾ����

���룺
A: [1,2,3,2,1]
B: [3,2,1,4,7]
�����3
���ͣ�
������Ĺ����������� [3, 2, 1] ��
 
��ʾ��
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int row = A.size() + 1, col = B.size() + 1;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int res = 0;
        for(int i = 1; i < row; ++i)
        {
            for(int j = 1; j < col; ++j)
            {
                if(A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};