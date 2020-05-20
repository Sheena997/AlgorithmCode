/*
752. ��ת����
����һ�������ĸ�Բ�β��ֵ�ת������ÿ�����ֶ���10�����֣�
 '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' ��ÿ��
 ���ֿ���������ת������� '9' ��Ϊ  '0'��'0' ��Ϊ '9' ��
 ÿ����ת��ֻ����תһ�����ֵ�һλ���֡�
���ĳ�ʼ����Ϊ '0000' ��һ�������ĸ����ֵ����ֵ��ַ�����
�б� deadends ������һ���������֣�һ�����ֵ����ֺ��б���
���κ�һ��Ԫ����ͬ����������ᱻ�����������޷��ٱ���ת��
�ַ��� target ������Խ��������֣�����Ҫ������С����ת������
���������β��ܽ��������� -1��

ʾ�� 1:
���룺deadends = ["0201","0101","0102","1212","2002"], target = "0202"
�����6
���ͣ�
���ܵ��ƶ�����Ϊ "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"��
ע�� "0000" -> "0001" -> "0002" -> "0102" -> "0202" �����������ǲ��ܽ����ģ�
��Ϊ�������� "0102" ʱ������ͻᱻ������
ʾ�� 2:
����: deadends = ["8888"], target = "0009"
�����1
���ͣ�
�����һλ������תһ�μ��� "0000" -> "0009"��
ʾ�� 3:
����: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
�����-1
���ͣ�
�޷���ת��Ŀ�������Ҳ���������
ʾ�� 4:
����: deadends = ["0000"], target = "8888"
�����-1

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/open-the-lock/
*/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadDict;
        for(string str : deadends)
            deadDict.insert(str);
        
        queue<string> q;
        unordered_set<string> visited;
        
        if(deadDict.find("0000") != deadDict.end())
            return -1;
        
        visited.insert("0000");
        q.push("0000");
        
        int res = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string curString = q.front();
                q.pop();
                if(curString == target)
                    return res;
                for(int i = 0; i < curString.size(); ++i)
                {
                    string newString1 = curString, newString2 = curString;
                    newString1[i] = newString1[i] == '9' ? '0' : newString1[i] + 1;
                    newString2[i] = newString2[i] == '0' ? '9' : newString2[i] - 1;
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