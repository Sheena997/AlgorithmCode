/*
752. 打开转盘锁
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字：
 '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个
 拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。
 每次旋转都只能旋转一个拨轮的一位数字。
锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里
的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，
如果无论如何不能解锁，返回 -1。

示例 1:
输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。
示例 2:
输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。
示例 3:
输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。
示例 4:
输入: deadends = ["0000"], target = "8888"
输出：-1

来源：LeetCode
链接：https://leetcode-cn.com/problems/open-the-lock/
*/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadDict;
        for(string str : deadends)
            deadDict.insert(str);
        
        queue<string> q;
		//标记列表
        unordered_set<string> visited;
        
        if(deadDict.find("0000") != deadDict.end())
            return -1;
        
		//队列和标记列表初始化
        visited.insert("0000");
        q.push("0000");
        
        int res = 0;
        
		//搜索
        while(!q.empty())
        {
			//当前队列中的所有字符串都是一次变换的结果
            int size = q.size();
            while(size--)
            {
				//获取队头字符串
                string curString = q.front();
                q.pop();
                if(curString == target)
                    return res;
				//变换当前字符串的一个字符
                for(int i = 0; i < curString.size(); ++i)
                {
					//每一位的字符有两种变换方式，上，下
                    string newString1 = curString, newString2 = curString;
					//向上拨
                    newString1[i] = newString1[i] == '9' ? '0' : newString1[i] + 1;
					//向下拨
                    newString2[i] = newString2[i] == '0' ? '9' : newString2[i] - 1;
					//判断新的字符是死亡数组，以及是否已经搜索过
                    if(deadDict.find(newString1) == deadDict.end()
                    && visited.find(newString1) == visited.end())
                    {
                        q.push(newString1);
                        visited.insert(newString1);
                    }
                    if(deadDict.find(newString2) == deadDict.end()
                    && visited.find(newString2) == visited.end())
                    {
                        q.push(newString2);
                        visited.insert(newString2);
                    }
                }
            }
            ++res;
        }
        
        return -1;
    }
};