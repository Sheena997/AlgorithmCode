/*
52. N皇后 II
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
示例:
输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
 

提示：
皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，
那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。
当然，她横、竖、斜都可走一或七步，可进可退。（引用自 百度百科 - 皇后 ）

来源：LeetCode
链接：https://leetcode-cn.com/problems/n-queens-ii/
*/
class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& res, vector<pair<int, int>>& vs, int n, int curRow)
    {
        if(curRow >= n)
        {
            if(curRow == n)
                res.push_back(vs);
            return;
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(isValid(vs, curRow, i))
            {
                vs.push_back(make_pair(curRow, i));
                dfs(res, vs, n, curRow + 1);
                vs.pop_back();
            }
        }
    }
    bool isValid(vector<pair<int, int>>& vs, int row, int col)
    {
        for(pair<int, int> e : vs)
        {
            if(e.second == col
              || e.first + e.second == row + col
              || e.first - e.second == row - col)
                return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        vector<vector<pair<int, int>>> res;
        vector<pair<int, int>> vs;
        
        dfs(res, vs, n, 0);
        
        return res.size();
    }
};