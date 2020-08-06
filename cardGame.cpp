/*
���ӣ�https://www.nowcoder.com/questionTerminal/7036f62c64ba4104a28deee98a6f53f6
��Դ��ţ����

[�����]ֽ�Ʋ���

��һ����������A��������ֵ��ͬ��ֽ���ų�һ���ߡ����a�����b��������ÿ��ֽ�ƣ��涨���a���ã�
���B���ã�����ÿ�����ÿ��ֻ��������������ҵ�ֽ�ƣ����a�����b�����������������ܻ�������Ų��ԡ��뷵������ʤ�ߵķ�����
����ֽ������A�����еĴ�Сn���뷵���������ϸ��ߵ÷���(��ͬ�򷵻�����һ������)����֤A�е�Ԫ�ؾ�С�ڵ���1000����A�Ĵ�СС�ڵ���300��

����������
[1,2,100,4],4
���أ�101
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