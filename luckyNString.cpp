/*
���ӣ�https://www.nowcoder.com/questionTerminal/3d08b635346d4610b01c6256bc07c394
��Դ��ţ����

[�����]����N��-�з�


СA��ϲ����ĸN������Ϊ������N�����������˴�����һ��СA������һ��ȫ���ɴ�д��ĸ��ɵ��ַ�����
��������ı����2����д��ĸ��Ҳ�����ı����ֻ�ı�1����д��ĸ����ʹ���ַ��������������
��������N���ĳ���������ܰ�������


��������:
����ĵ�һ����һ��������T��0 < T <= 20������ʾ��T��������ݡ�����ÿһ���������ݰ���һ�д�д��
����S��0 < |S| <= 50000��|S|��ʾ�ַ������ȣ���

���ݷ�Χ��

20%�������У��ַ������Ȳ�����100��

70%�������У��ַ������Ȳ�����1000��

100%�������У��ַ������Ȳ�����50000��


�������:
����ÿһ��������������һ����������ʾ������������������N���ĳ��ȡ�
ʾ��1
����
3
NNTN
NNNNGGNNNN
NGNNNNGNNNNNNNNSNNNN
���
4
10
18
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0; 
    cin >> n;
    int dp[50002][3];
    while(n--)
    {
        string str;
        cin >> str;
        if(str.empty())
            cout << 0 << endl;
        
        dp[0][0] = ((str[0] == 'N') ? 1 : 0);
        dp[0][1] = dp[0][2] = 1;
        int resMax = 1;
        for(int i = 1; i < str.size(); ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                if(str[i] == 'N')
                {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
                else
                {
                    dp[i][j] = 0;
                    ++j;
                    while(j < 3)
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        ++j;
                    }
                }
            }
            
            resMax = max(resMax, max(max(dp[i][0], dp[i][1]), dp[i][2]));
        }
        
        cout << resMax << endl;
    }
    
    return 0;
}