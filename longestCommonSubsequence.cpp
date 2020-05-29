/*
1143. �����������
���������ַ��� text1 �� text2�������������ַ���������������еĳ��ȡ�

һ���ַ����� ������ ��ָ����һ���µ��ַ�����������ԭ�ַ����ڲ��ı��ַ�
�����˳��������ɾ��ĳЩ�ַ���Ҳ���Բ�ɾ���κ��ַ�������ɵ����ַ�����
���磬"ace" �� "abcde" �������У��� "aec" ���� "abcde" �������С�����
�ַ����ġ����������С����������ַ�������ͬӵ�е������С�
���������ַ���û�й��������У��򷵻� 0��
ʾ�� 1:
���룺text1 = "abcde", text2 = "ace" 
�����3  
���ͣ�������������� "ace"�����ĳ���Ϊ 3��
ʾ�� 2:
���룺text1 = "abc", text2 = "abc"
�����3
���ͣ�������������� "abc"�����ĳ���Ϊ 3��
ʾ�� 3:
���룺text1 = "abc", text2 = "def"
�����0
���ͣ������ַ���û�й��������У����� 0��
 

��ʾ:
1 <= text1.length <= 1000
1 <= text2.length <= 1000
������ַ���ֻ����СдӢ���ַ���

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/longest-common-subsequence/
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size() + 1, len2 = text2.size() + 1;
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        
        for(int i = 1; i < len1; ++i)
        {
            for(int j = 1; j < len2; ++j)
            {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[len1 - 1][len2 - 1];
    }
};