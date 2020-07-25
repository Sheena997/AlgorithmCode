/*
���ӣ�https://www.nowcoder.com/questionTerminal/6f0d16fc06274f44af8913d182668037
��Դ��ţ����

[�����]�������


С��������������Զ���⣬�����֣���ĳЩlibrary �Ĵ���εĶ����Ʊ�ʾ�У���������Ӵ�����ǡ����k��1��
���п�����Ǳ�ڵĲ�����library�Ķ����Ʊ�ʾ���ܴܺ󣬲����Ӵ����ܺܶ࣬�˹����������ܣ���������д����
���������㵽���ж��ٸ��Ӵ���������������Ӵ�������ͬ�����ǿ�ʼ���߽���λ�ò�һ��������Ϊ�ǲ�ͬ���Ӵ���
ע���Ӵ�һ���������ġ�����"010"��6���Ӵ����ֱ��� "0, "1", "0", "01", "10", "010"


��������:
��һ����һ������k����ʾ�Ӵ�����k��1���п����ǲ��������� 0 <= k <= 1 000 000

�ڶ�����һ���ַ���������library�Ĵ��벿�ֵĶ����Ʊ�ʾ���ַ������� <= 1 000 000�������ַ�����ֻ����"0"��"1".


�������:
���һ����������������ֻ����k��1���Ӵ��ĸ�����
ʾ��1
����
1
1010
���
6
˵��
�����������Ӵ��У�"1", "1", "10", "01", "10", "010".
ʾ��2
����
2
01010
���
4
˵��
�����������Ӵ��У� "101", "0101", "1010", "01010".
ʾ��3
����
100
01010
���
0
*/
#include <iostream>
#include <string>

using namespace std;

long countTheSubstring(string str, long k)
{
    long res = 0;
    for(long i = 0; i < str.size(); ++i)
    {
        long right = i, count = 0;
        while(right < str.size() && count < k)
        {
            if(str[right] == '1' && ++count == k)
            {
                ++right;
                ++res;
                break;
            }
            ++right;
        }
        
        while(right < str.size() && str[right] != '1')
        {
            ++right;
            ++res;
        }
    }
    
    return res;
}
int main()
{
    long k = 0;
    cin >> k;
    string str = "";
    cin >> str;
    long res  = 0;
    for(auto& e : str)
        if(e == '1')
            ++res;
    
    if(res < k)
        cout << 0 << endl;
    else
        cout << countTheSubstring(str, k) << endl;
    
    return 0;
}