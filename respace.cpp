/*
������ 17.13. �ָ��ո�
Ŷ�������㲻С�İ�һ����ƪ�����еĿո񡢱�㶼ɾ���ˣ�
���Ҵ�дҲŪ����Сд�������"I reset the computer. It 
still didn��t boot!"�Ѿ������"iresetthecomputeritstilldidntboot"��
�ڴ�������źʹ�Сд֮ǰ������Ȱ����ϳɴ����Ȼ�ˣ�����һ����
��Ĵʵ�dictionary����������Щ��û�ڴʵ������������sentence��ʾ��
���һ���㷨�������¶Ͽ���Ҫ��δʶ����ַ����٣�����δʶ����ַ�����
ע�⣺�������ԭ�������Ķ���ֻ�践��δʶ����ַ���

ʾ����

���룺
dictionary = ["looked","just","like","her","brother"]
sentence = "jesslookedjustliketimherbrother"
����� 7
���ͣ� �Ͼ��Ϊ"jess looked just like tim her brother"����7��δʶ���ַ���
��ʾ��

0 <= len(sentence) <= 1000
dictionary�����ַ��������� 150000��
�������Ϊdictionary��sentence��ֻ����Сд��ĸ

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/re-space-lcci/
*/
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        vector<int> dp(n + 1, 0);
        for(int i = 1; i < n + 1; ++i)
        {
            dp[i] = dp[i - 1] + 1;
            for(auto e : dictionary)
            {
                if(e.size() <= i)
                {
                    if(e == sentence.substr(i - e.size(), e.size()))
                        dp[i] = min(dp[i], dp[i - e.size()]);
                }
            }
        }
        
        return dp[n];
    }
};