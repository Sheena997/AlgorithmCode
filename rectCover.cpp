/*
���ǿ�����2*1��С���κ��Ż�������ȥ��
�Ǹ���ľ��Ρ�������n��2*1��С��������
���ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
����n=3ʱ��2*3�ľ��ο���3�ָ��Ƿ�����

��Դ��ţ����
���ӣ�https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6
*/
class Solution {
public:
    int rectCover(int number) {
        if(number < 1)
            return 0;
        if(number < 2)
            return 1;
        vector<int> dp(number, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < number; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[number - 1];
    }
};