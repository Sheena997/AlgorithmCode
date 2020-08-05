/*
���ӣ�https://www.nowcoder.com/questionTerminal/138f0ae35154438caf3d0072bd6ffef5
��Դ��ţ����

[�����]�ַ����������

���������ַ���A��B��C�����ǳ�C��A��B������ɵ��ҽ���C�����ҽ�����A��B�������ַ����Ҷ�Ӧ��˳�򲻸ı䡣
���дһ����Ч�㷨���ж�C���Ƿ���A��B������ɡ�

���������ַ���A,B��C�������ǵĳ��ȡ��뷵��һ��boolֵ������C�Ƿ���A��B������ɡ���֤�������ĳ��Ⱦ�С�ڵ���100��

����������
"ABC",3,"12C",3,"A12BCC",6
���أ�true
*/
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        // write code here
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        //��ʼ��
        dp[0][0] = true;
        for(int i = 1; i < n + 1; ++i)
            dp[i][0] = (dp[i - 1][0] && A[i - 1] == C[i - 1]);
        for(int j = 1; j < m + 1; ++j)
            dp[0][j] = (dp[0][j - 1] && B[j - 1] == C[j - 1]);
        
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 1; j < m + 1; ++j)
            {
                dp[i][j] = ((dp[i - 1][j] && A[i - 1] == C[i + j - 1]) || (dp[i][j - 1] && B[j - 1] == C[i + j - 1]));
            }
        }
        
        return dp[n][m];
    }
};

