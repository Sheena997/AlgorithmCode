/*
127. ���ʽ���
�����������ʣ�beginWord �� endWord����һ���ֵ䣬�ҵ��� beginWord �� endWord �����ת�����еĳ��ȡ�ת������ѭ���¹���

ÿ��ת��ֻ�ܸı�һ����ĸ��
ת�������е��м䵥�ʱ������ֵ��еĵ��ʡ�
˵��:

���������������ת�����У����� 0��
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��
ʾ�� 1:

����:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

���: 5

����: һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     �������ĳ��� 5��
ʾ�� 2:

����:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

���: 0

����: endWord "cog" �����ֵ��У������޷�����ת����

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/word-ladder/
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty())
            return 0;
        unordered_set<string> wordDict;
        
        for(auto& e : wordList)
            wordDict.insert(e);
        
        if(wordDict.find(endWord) == wordDict.end())
            return 0;
        
        int res = 1;
        unordered_set<string> visited;
        queue<string> q;
        visited.insert(beginWord);
        
        q.push(beginWord);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string curWord = q.front();
                q.pop();
                for(int i = 0; i < curWord.size(); ++i)
                {
                    string newWord = curWord;
                    for(char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        newWord[i] = ch;
                        if(newWord == endWord)
                            return res + 1;
                        if(wordDict.find(newWord) != wordDict.end()
                        && visited.find(newWord) == visited.end())
                        {
                            q.push(newWord);
                            visited.insert(newWord);
                        }
                    }   
                }
            }
            ++res;
        }
        
        return 0;
    }
};