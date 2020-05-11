/*
��Ŀ����
����һ���ַ���S��һ���ַ���T������S�е�T�Ĳ�ͬ�����еĸ�����
�ַ���������������ԭ�����ַ���ɾ��һЩ�ַ���Ҳ���Բ�ɾ����
�ڲ��ı����λ�õ�����µ�ʣ���ַ������磬"ACE"is a subsequence of"ABCDE"����"AEC"���ǣ�
���磺
S ="rabbbit", T ="rabbit"
����3

��Դ��ţ����
���ӣ�https://www.nowcoder.com/practice/ed2923e49d3d495f8321aa46ade9f873?tpId=46&tqId=29065&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int row = S.size(), col = T.size();
        if(col == 0)
            return 1;
        if(row == 0)
            return 0;
        
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        
        //��ʼ��
        for(int i = 0; i < row + 1; ++i)
            dp[i][0] = 1;
        
        //����
        for(int i = 1; i < row + 1; ++i)
        {
            for(int j = 1; j < col + 1; ++j)
            {
                /*
                if(S[i - 1] == T[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
                 */
                dp[i][j] = dp[i - 1][j] + (S[i -1] == T[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        
        return dp[row][col];
    }
};