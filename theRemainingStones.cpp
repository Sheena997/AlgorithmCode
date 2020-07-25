/*
���ӣ�https://www.nowcoder.com/questionTerminal/9dd19c9305704138bdf83e2dffdcb4f4
��Դ��ţ����

[�����]ʯͷ��ײ


����һ��ʯͷ��ÿ��ʯͷ��һ��������������ÿһ�ֿ�ʼ��ʱ��ѡ������ʯͷһ����ײ��
�ٶ�����ʯͷ������Ϊx��y��x<=y,��ײ���Ϊ
1. ���x==y����ײ���Ϊ����ʯͷ��ʧ
2. ���x != y����ײ�������ʯͷ��ʧ������һ���µ�ʯͷ����ʯͷ����Ϊy-x

�������ʣ��һ��ʯͷΪ�����������С��ʣ��ʯͷ�����Ŀ������Ƕ��١�

��������:
��һ������ʯͷ����(<=100)

�ڶ�������ʯͷ�������Կո�ָʯͷ�����ܺ�<=10000


�������:
���յ�ʯͷ����
ʾ��1
����
6
2 7 4 1 8 1
���
1
*/
#include <iostream>
#include <vector>

using namespace std;

int theRemainingStones(vector<int> stones, int sum)
{
    int row = stones.size() + 1, col = sum / 2 + 1;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for(int i = 1; i < row; ++i)
    {
        for(int j = 1; j < col; ++j)
        {
            if(stones[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
        }
    }
    
    return sum - 2 * dp[row - 1][col - 1];
}
int main()
{
    int n = 0, sum = 0;
    cin >> n;
    vector<int> stones(n, 0);
    for(auto& e : stones)
    {
        cin >> e;
        sum += e;
    }
    
    cout << theRemainingStones(stones, sum) << endl;
    
    return 0;
}