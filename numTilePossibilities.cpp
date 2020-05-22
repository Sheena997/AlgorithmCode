/*
1079. ����ӡˢ
����һ�׻�����ģ tiles������ÿ����ģ�϶�����һ����ĸ tiles[i]�����������ӡ���ķǿ���ĸ���е���Ŀ��

ע�⣺�����У�ÿ��������ģֻ��ʹ��һ�Ρ�

 

ʾ�� 1��

���룺"AAB"
�����8
���ͣ����ܵ�����Ϊ "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"��
ʾ�� 2��

���룺"AAABBC"
�����188
 

��ʾ��

1 <= tiles.length <= 7
tiles �ɴ�дӢ����ĸ���

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/letter-tile-possibilities/
*/
class Solution {
public:
    void dfs(string tiles, unordered_set<string>& us, vector<int>& visited, string curStr)
    {
        //����ÿһ���ǿ��ַ���
        //set��Ȼ��ȥ��
        if(!curStr.empty())
            us.insert(curStr);
        
        for(int i = 0; i < tiles.size(); ++i)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
            
                //ƴ��
                dfs(tiles, us, visited, curStr + tiles[i]);
            
                //����
                visited[i] = 0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        if(tiles.empty())
            return 0;
        
        unordered_set<string> us;
        vector<int> visited(tiles.size(), 0);
        
        dfs(tiles, us, visited, "");
        
        return us.size();
    }
};