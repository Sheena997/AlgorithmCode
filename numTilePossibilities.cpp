/*
1079. 活字印刷
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。

注意：本题中，每个活字字模只能使用一次。

 

示例 1：

输入："AAB"
输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
示例 2：

输入："AAABBC"
输出：188
 

提示：

1 <= tiles.length <= 7
tiles 由大写英文字母组成

来源：LeetCode
链接：https://leetcode-cn.com/problems/letter-tile-possibilities/
*/
class Solution {
public:
    void dfs(string tiles, unordered_set<string>& us, vector<int>& visited, string curStr)
    {
        //保存每一个非空字符串
        //set天然的去重
        if(!curStr.empty())
            us.insert(curStr);
        
        for(int i = 0; i < tiles.size(); ++i)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
            
                //拼接
                dfs(tiles, us, visited, curStr + tiles[i]);
            
                //回溯
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