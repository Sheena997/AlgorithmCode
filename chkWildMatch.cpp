/*
���ӣ�https://www.nowcoder.com/questionTerminal/28acd1134e344040ad105b3786a79e7a
��Դ��ţ����

[�����]�ַ���ͨ��

�����ַ���A�����о��Բ������ַ���.���͡�*�����ٸ����ַ���B�����п��Ժ��С�.����*������*���ַ�������
B�����ַ�����������������*���ַ������ڡ�exp�еġ�.�������κ�һ���ַ���B�еġ�*����ʾ��*����ǰһ����
��������0�����߶������дһ���������ж�A�Ƿ��ܱ�Bƥ�䡣

���������ַ���A��B,ͬʱ�����������ĳ���lena��lenb���뷵��һ��boolֵ�����ܷ�ƥ�䡣��֤�����ĳ��Ⱦ�С�ڵ���300��

����������
"abcd",4,".*",2
���أ�true
*/
class WildMatch {
public:
    bool chkWildMatch(string A, int lena, string B, int lenb) {
        // write code here
        vector<vector<bool>> dp(lena + 1, vector<bool>(lenb + 1, false));
        
        dp[0][0] = true;
        
        for(int i = 1; i < lena + 1; ++i)
        {
            for(int j = 1; j < lenb + 1; ++j)
            {
                if(B[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(B[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = (dp[i - 1][j - 1] && A[i - 1] == B[j - 1]);
            }
        }
        
        return dp[lena][lenb];
    }
};