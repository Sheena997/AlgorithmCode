/*
279. ��ȫƽ����
���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��
ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ������١�

ʾ�� 1:

����: n = 12
���: 3 
����: 12 = 4 + 4 + 4.
ʾ�� 2:

����: n = 13
���: 2
����: 13 = 4 + 9.

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/perfect-squares/
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