/*
1052. 爱生气的书店老板
今天，书店老板有一家店打算试营业 customers.length 分钟。每分钟都有一些顾客（customers[i]）会进入书店，
所有这些顾客都会在那一分钟结束后离开。
在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 
当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。
书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 X 分钟不生气，但却只能使用一次。
请你返回这一天营业下来，最多有多少客户能够感到满意的数量。
示例：
输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
输出：16
解释：
书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.

来源：LeetCode
链接：https://leetcode-cn.com/problems/grumpy-bookstore-owner/
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int num = 0, ret = 0, res = 0;
        for(int i = 0; i < grumpy.size(); ++i)
        {
            if(grumpy[i] == 0)
                ret += customers[i];
            else
                if(i < X)
                    num += customers[i];
        }
        res = num + ret;
        for(int i = X; i < grumpy.size(); ++i)
        {
            if(grumpy[i] == 1)
                num += customers[i];
            if(grumpy[i - X] == 1)
                num -= customers[i - X];
            res = max(res, ret + num);
        }
        
        return res;
    }
};

/*
滑动窗口
思路：结果分成两部分。不生气时的人数一定要全部累加上。此时，只需要求出窗口中，生气时的最大人数和即可。用滑动窗口法求窗口中生气时的最大人数和。
例如：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
不生气的位置 [1,0,1,2,1,1,7,5]
不生气的总人数 = 1 + 1 + 1 + 7 = 10
窗口中生气的人数 最大的位置 [1,0,1,2,1,1,7,5]
窗口中生气的最大人数和 = 1+5 = 6
*/
