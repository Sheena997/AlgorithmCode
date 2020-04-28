/*
链接：https://www.nowcoder.com/questionTerminal/7e157ce9a8c249daa3ddafad322dbf1e
来源：牛客网

[编程题]0/1 背包问题

有为N件物品，它们的重量w分别是w1,w2,...,wn，它们的价值v分别是v1,v2,...,vn，每
件物品数量有且仅有一个，现在给你个承重为M的背包，求背包里装入的物品具有的价值最大总和？
输入描述:
物品数量N=5件
重量w分别是2 2 6 5 4
价值v分别是6 3 5 4 6
背包承重为M=10
输出描述:
背包内物品最大总和为15
示例1
输入
5
10
2 2 6 5 4
6 3 5 4 6
输出
15
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int BagProblem(int n, int m, vector<int> w, vector<int> v)
{
	if(v.empty() || w.empty() || m < 1)
        return 0;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for(int i = 1; i < n + 1; ++i)
    {
        for(int j = 1; j < m + 1; ++j)
        {
            if(w[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }

	return dp[n][m];
}
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
		vector<int> w(n, 0);
		vector<int> v(n, 0);
		for (auto& e : w)
			cin >> e;
		for (auto& e : v)
			cin >> e;

		int res = BagProblem(n, m, w, v);

		cout << res << endl;

	return 0;
}