/*
链接：https://www.nowcoder.com/questionTerminal/7036f62c64ba4104a28deee98a6f53f6
来源：牛客网

[编程题]纸牌博弈

有一个整型数组A，代表数值不同的纸牌排成一条线。玩家a和玩家b依次拿走每张纸牌，规定玩家a先拿，
玩家B后拿，但是每个玩家每次只能拿走最左或最右的纸牌，玩家a和玩家b都绝顶聪明，他们总会采用最优策略。请返回最后获胜者的分数。
给定纸牌序列A及序列的大小n，请返回最后分数较高者得分数(相同则返回任意一个分数)。保证A中的元素均小于等于1000。且A的大小小于等于300。

测试样例：
[1,2,100,4],4
返回：101
*/
class Cards {
public:
    int cardGame(vector<int> A, int n) {
        // write code here
        vector<vector<int>> fst(n, vector<int>(n, 0));
        vector<vector<int>> lst(n, vector<int>(n, 0));
        
        for(int r = 0; r < n; ++r)
        {
            fst[r][r] = A[r];
            lst[r][r] = 0;
            for(int l = r - 1; l >= 0; --l)
            {
                fst[l][r] = max(A[l] + lst[l + 1][r], A[r] + lst[l][r - 1]);
                lst[l][r] = min(fst[l + 1][r], fst[l][r - 1]);
            }
        }
        
        return max(fst[0][n - 1], lst[0][n - 1]);
    }
};