/*
��������
�������һ�����е��������ǰһ���ż�����ǰһ��С�����Ϊһ���ڶ����С��� a[2i]<a[2i-1], a[2i+1]>a[2i]��
����С����֪��������Ϊ m��ÿ�������� 1 �� n ֮����������İڶ�����һ���ж��ٸ���
�����ʽ
��������һ�а����������� m��n��
�����ʽ
�������һ����������ʾ�𰸡��𰸿��ܴܺ�������𰸳���10000��������
��������
3 4
�������
14
����˵��
���������Ƿ���Ҫ��İڶ����У�
����2 1 2
����2 1 3
����2 1 4
����3 1 2
����3 1 3
����3 1 4
����3 2 3
����3 2 4
����4 1 2
����4 1 3
����4 1 4
����4 2 3
����4 2 4
����4 3 4
*/
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> >dp(1001, vector<int>(1001, 0));
int countSwingMatrix(int m, int n)
{
    for(int i = 1; i <= n; ++i)
        dp[1][i] = n - i + 1;
    for(int i = 2; i <= m; ++i)
    {
        if(i & 1)
        {
            for(int j = n; j >= 1; --j)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j + 1]) % 10000;
        }
        else
        {
            for(int j = 1; j <= n; ++j)
                dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % 10000;
        }
    }
    
    return (m & 1 ? dp[m][1] : dp[m][n]);
}
int main()
{
    int m = 0, n = 0;
    while(cin >> m >> n)
    {
        int res = countSwingMatrix(m, n);
        
        cout << res << endl;
    }
    
    return 0;
}
