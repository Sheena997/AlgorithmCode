/*
343. �������
����һ�������� n��������Ϊ���������������ĺͣ���ʹ��Щ�����ĳ˻���󻯡� 
��������Ի�õ����˻���

ʾ�� 1:

����: 2
���: 1
����: 2 = 1 + 1, 1 �� 1 = 1��
ʾ�� 2:

����: 10
���: 36
����: 10 = 3 + 3 + 4, 3 �� 3 �� 4 = 36��
˵��: ����Լ��� n ��С�� 2 �Ҳ����� 58��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/integer-break/
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i < n + 1; ++i)
        {
            for(int j = i - 1; j >= 1; --j)
            {
                dp[i] = max(dp[i], dp[j] * (i - j)); //���Ϊ�������ʱ��
                dp[i] = max(dp[i], j * (i - j)); //���Ϊ��������ʱ��
            }
        }
        
        return dp[n];
    }
};

