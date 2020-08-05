/*
���ӣ�https://www.nowcoder.com/questionTerminal/dfa502cf6a914fb5b98c59c56619e96c
��Դ��ţ����

[�����]��С�༭����
�ȶ�ָ����1295ʱ�����ƣ�C/C++ 2�룬��������4��ռ����ƣ�C/C++ 256M����������512M
�㷨֪ʶ��Ƶ����
���������ַ���str1��str2���ٸ�����������ic��dc��rc���ֱ������롢ɾ�����滻һ���ַ��Ĵ��ۣ��������str1�༭��str2����С���ۡ�

��������:
������У���һ�к͵ڶ��о�Ϊһ���ַ������ֱ��ʾ�����ַ���str1��str2��
\left( 1\leq length(str1),length(str2) \leq 5000 \right)(1��length(str1),length(str2)��5000)��
������Ϊ����������������ic��dc��rc����1<=ic<=10000��1<=dc<=10000��1<=rc<=10000��


�������:
���һ����������ʾ�༭����С���ۡ�
ʾ��1
����
abc
adc
5 3 2
���
2
ʾ��2
����
abc
adc
5 3 100
���
8
ʾ��3
����
abc
abc
5 3 2
���
0

��ע:
ʱ�临�Ӷ�O(n*m)O(n?m)���ռ临�Ӷ�O(n)O(n)��(n,m���������ַ�������)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDistance(string str1, string str2, int ic, int dc, int rc)
{
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    
    for(int i = 0; i < str1.size() + 1; ++i)
        dp[i][0] = i * dc;
    for(int j = 0; j < str2.size() + 1; ++j)
        dp[0][j] = j * ic;
    
    for(int i = 1; i < str1.size() + 1; ++i)
    {
        for(int j = 1; j < str2.size() + 1; ++j)
        {
            dp[i][j] = min(dp[i - 1][j] + dc, dp[i][j - 1] + ic);
            dp[i][j] = min(dp[i][j], (str1[i - 1] == str2[j - 1]) ? (dp[i - 1][j - 1]) : (dp[i - 1][j - 1] + rc));
        }
    }
    
    return dp[str1.size()][str2.size()];
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int ic = 0, dc = 0, rc = 0;
    cin >> ic >> dc >> rc;
    
    cout << minDistance(str1, str2, ic, dc, rc) << endl;
    
    return 0;
}