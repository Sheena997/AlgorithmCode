/*
279. 完全平方数
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）
使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：LeetCode
链接：https://leetcode-cn.com/problems/perfect-squares/
*/
class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        vector<int> visited(n + 1, 0);
        visited[n] = 1;
        
        while(!q.empty())
        {
            int num = q.front().first;
            int step = q.front().second;
            
            q.pop();
            
            for(int i = 1; num - i * i >= 0; ++i)
            {
                int a = num - i * i;
                if(a < 0)
                    break;
                if(a == 0)
                    return step + 1;
                if(visited[a] == 0)
                    q.push(make_pair(a, step + 1));
                
                visited[a] = 1;
            }
        }
        
        return 0;
    }
};