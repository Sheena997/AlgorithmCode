/*
题目：问题描述：分别有1, 5, 10, 50, 100元， 分别有5, 2, 2, 3, 5张纸币。问若要支付k元，则最少需要多少张纸币？

解题思路：每次选择支付的纸币时，尽量选择面额最大的，这样每次获得的都是局部最优的选择，直到满足 k 元为止
*/
#include <iostream>
#include <vector>

using namespace std;

int countTheCash(vector<int> cash, vector<int> count, int k)
{
	int res = 0;

	for (int i = cash.size() - 1; i >= 0; --i)
	{
		if (k >= cash[i] && count[i] > 0)
		{
			--count[i];
			k -= cash[i];
			++res;
		}
	}

	if (k != 0)
		return -1;

	return res;
}
int main()
{
	vector<int> cash = { 1,5,10,50,100 };
	vector<int> count(5);

	for (auto& e : count)
		cin >> e;
	int k = 0;
	cin >> k;
	
	cout << countTheCash(cash, count, k) << endl;

	return 0;
}