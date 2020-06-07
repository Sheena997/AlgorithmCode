/*
1306. ��Ծ��Ϸ III
������һ���Ǹ��������� arr�����ʼλ�ڸ��������ʼ�±� start ����
����λ���±� i ��ʱ����������� i + arr[i] ���� i - arr[i]��
�����ж��Լ��Ƿ��ܹ�������ӦԪ��ֵΪ 0 �� ���� �±괦��
ע�⣬������ʲô����£��㶼�޷���������֮�⡣
ʾ�� 1��

���룺arr = [4,2,3,0,3,1,2], start = 5
�����true
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ����� 
�±� 5 -> �±� 4 -> �±� 1 -> �±� 3 
�±� 5 -> �±� 6 -> �±� 4 -> �±� 1 -> �±� 3 
ʾ�� 2��

���룺arr = [4,2,3,0,3,1,2], start = 0
�����true 
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ����� 
�±� 0 -> �±� 4 -> �±� 1 -> �±� 3
ʾ�� 3��

���룺arr = [3,0,2,1,2], start = 2
�����false
���ͣ��޷�����ֵΪ 0 ���±� 1 ���� 
 

��ʾ��

1 <= arr.length <= 5 * 10^4
0 <= arr[i] < arr.length
0 <= start < arr.length

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/jump-game-iii/
*/
class Solution {
public:
    void dfs(vector<int>& arr, vector<int>& visited, bool& flag, int index)
    {
        if(arr[index] == 0)
        {
            flag = true;
            return;
        }
        
        visited[index] = 1;
        if(index - arr[index] >= 0 && index - arr[index] < arr.size() && visited[index - arr[index]] == 0)
            dfs(arr, visited, flag, index - arr[index]);
        if(index + arr[index] >= 0 && index + arr[index] < arr.size() && visited[index + arr[index]] == 0)
            dfs(arr, visited, flag, index + arr[index]);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        bool flag = false;
        
        dfs(arr, visited, flag, start);
        
        return flag;
    }
};