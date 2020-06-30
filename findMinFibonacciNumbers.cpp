/*
1414. ��Ϊ K ������쳲�����������Ŀ
�������� k �����㷵�غ�Ϊ k ��쳲��������ֵ�������Ŀ��
���У�ÿ��쳲��������ֶ����Ա�ʹ�ö�Ρ�쳲��������ֶ���Ϊ��
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 �� ���� n > 2 ��
���ݱ�֤���ڸ����� k ��һ�����ҵ����н⡣

ʾ�� 1��
���룺k = 7
�����2 
���ͣ�쳲���������Ϊ��1��1��2��3��5��8��13������
���� k = 7 �����ǿ��Եõ� 2 + 5 = 7 ��

ʾ�� 2��
���룺k = 10
�����2 
���ͣ����� k = 10 �����ǿ��Եõ� 2 + 8 = 10 ��

ʾ�� 3��
���룺k = 19
�����3 
���ͣ����� k = 19 �����ǿ��Եõ� 1 + 5 + 13 = 19 ��
 

��ʾ��

1 <= k <= 10^9
ͨ������3,130�ύ����5,747

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
*/
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int f1 = 1, f2 = 1, res = 0;
        vector<int> fib = {f1, f2};
        while(f1 + f2 <= k)
        {
            int f3 = f1 + f2;
            fib.push_back(f3);
            f1 = f2;
            f2 = f3;
        }
        
        for(int i = fib.size() - 1; i >= 0; --i)
        {
            if(fib[i] <= k)
            {
                ++res;
                k -= fib[i];
            }
        }
        
        return res;
    }
};