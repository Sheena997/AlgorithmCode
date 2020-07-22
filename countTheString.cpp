/*
��Ŀ����
������⡿����������ת��Ϊ�ַ�����ԭ�����£�1��Ӧ a��2��Ӧb����..26��Ӧz��
����12258����ת��Ϊ"abbeh", "aveh", "abyh", "lbeh" and "lyh"������Ϊ5��
��дһ����������������ת���Ĳ�ͬ�ַ����ĸ�����
*/
int countTheString(string str)
{
    vector<int> dp(str.size() + 1);
    dp[0] = 1;
    dp[1] = str[0] - '0' > 0 ? 1 : 0;
    for(int i = 2; i < str.size() + 1; ++i)
    {
        int first = str[i - 1] - '0';
        if(first != 0)
            dp[i] += dp[i - 1];
        if(str[i - 2] - '0' == 0)
            continue;
        
        dp[i] += ((str[i - 2] - '0') * 10 + (str[i - 1] - '0')) <= 26 ? dp[i - 2] : 0; 
    }
    
    return dp[str.size()];
}