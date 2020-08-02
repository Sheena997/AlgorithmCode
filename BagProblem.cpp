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

	vector<int> dp(m + 1, 0);

	for(int i = 1; i < n + 1; ++i)
    {
        for(int j = m; j >= w[i - 1]; --j)
        {
			dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - ]);
        }
    }

	return dp[m];
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


//完全背包
/*
有编号分别为a,b,c,d的四件物品，它们的重量分别是2,3,4,7，
它们的价值分别是1,3,5,9，每件物品数量无限个，现在给你个
承重为10的背包，如何让背包里装入的物品具有最大的价值总和？

完全背包问题与01背包问题的区别在于每一件物品的数量都有无限个，
而01背包每件物品数量只有一个。
*/
int BagProblem(int n, int m, vector<int> w, vector<int> v)
{
	if(v.empty() || w.empty() || m < 1)
        return 0;

	vector<int> dp(m + 1, 0);
	for(int i = 1; i < n + 1; ++i)
	{
		for(int j = w[i - 1]; j < m + 1; ++j)
			dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
	}
	return dp[m];
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





//多重背包：
/*
有编号分别为a,b,c的三件物品，它们的重量分别是1，2，2，它们
的价值分别是6，10，20，他们的数目分别是10，5，2，现在给你个
承重为 8 的背包，如何让背包里装入的物品具有最大的价值总和？

有 n 种物品和一个承重是 m 的背包。第 i 种物品最多有 si 件，每件重量是 wi，价值是 vi。
求解将哪些物品装入背包，可使物品重量总和不超过背包容量，且价值总和最大。输出最大价值。

多重背包和01背包、完全背包的区别：多重背包中每个物品的个数都
是给定的，可能不是一个，绝对不是无限个。
*/
int BagProblem(int n, int m, vector<int> w, vector<int> v, vector<int> s)
{
	if(v.empty() || w.empty() || m < 1)
        return 0;

	vector<int> dp(m + 1, 0);
	for(int i = 1; i < n + 1; ++i)
	{
		for(int j = m; j >= 0; --j)
		{
			for(int k = 1; k <= s[i - 1] && k * w[i - 1] <= j; ++k)
				fp[j] = max(dp[j], dp[j - k * w[i - 1]] + k * v[i - 1]);
		}
	}
	return dp[m];
}