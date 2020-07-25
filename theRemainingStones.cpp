/*
链接：https://www.nowcoder.com/questionTerminal/9dd19c9305704138bdf83e2dffdcb4f4
来源：牛客网

[编程题]石头碰撞


给定一组石头，每个石头有一个正数的重量。每一轮开始的时候，选择两个石头一起碰撞，
假定两个石头的重量为x，y，x<=y,碰撞结果为
1. 如果x==y，碰撞结果为两个石头消失
2. 如果x != y，碰撞结果两个石头消失，生成一个新的石头，新石头重量为y-x

最终最多剩下一个石头为结束。求解最小的剩余石头质量的可能性是多少。

输入描述:
第一行输入石头个数(<=100)

第二行输入石头质量，以空格分割，石头质量总和<=10000


输出描述:
最终的石头质量
示例1
输入
6
2 7 4 1 8 1
输出
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