/*
来源：牛客网
链接：https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的
后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
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