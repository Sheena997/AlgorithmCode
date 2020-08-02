/*
��Դ��ţ����
���ӣ�https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ����
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ�������
��벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() <= 0)
            return;
        int k = 0;
        for(int i = 0; i < array.size(); ++i)
        {
            if((array[i] & 1) == 1)
            {
                int tmp = array[i], j = i;
                while(j > k)
                {
                    array[j] = array[j - 1];
                    --j;
                }
                array[k++] = tmp;
            }
        }
    }
};