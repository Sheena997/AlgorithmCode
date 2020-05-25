/*
51. N皇后
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，
该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:
输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 

提示：
皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，
那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。
当然，她横、竖、斜都可走一到七步，可进可退。（引用自 百度百科 - 皇后 ）
*/
class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& solutions, vector<pair<int, int>>& solution, int curRow, int n)
    {
        //当每一行的位置都确定之后，保存方案
        if(n == curRow)
        {
            solutions.push_back(solution);
            return;
        }
        
        //对于当前行遍历每一列可能的位置
        for(int i = 0; i < n; ++i)
        {
            if(isValid(solution, curRow, i))
            {
                //保存当前皇后的位置
                solution.push_back(make_pair(curRow, i));
            
                //确定下一行的皇后的位置
                dfs(solutions, solution, curRow + 1, n);
            
                //尝试下一列的位置，回溯
                solution.pop_back();
            }
        }
    }
    
    bool isValid(vector<pair<int, int>>& solution, int row, int col)
    {
        //保证和每一个皇后的位置都不冲突
        for(pair<int, int> pos : solution)
        {
            //不再同一列且不在同一斜线上
            if(pos.second == col
              || pos.first + pos.second == row + col
              || pos.first - pos.second == row - col)
                return false;
        }
        
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int, int>>> solutions;
        vector<pair<int, int>> solution;
        
        dfs(solutions, solution, 0, n);
        
        return trans(solutions, n);
    }
    
    vector<vector<string>> trans(vector<vector<pair<int, int>>>& solutions, int n)
    {
        vector<vector<string>> res;
        //转换每一个方案
        for(vector<pair<int, int>> s : solutions)
        {
            vector<string> vs(n, string(n, '.'));//n行n个‘.’
            for(pair<int, int> pos : s)
            {
                //皇后的位置赋值为'Q'
                vs[pos.first][pos.second] = 'Q';
            }
            //转换好的一种方案
            res.push_back(vs);
        }
        
        return res;
    }
};