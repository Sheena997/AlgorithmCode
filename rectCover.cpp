/*
我们可以用2*1的小矩形横着或者竖着去覆
盖更大的矩形。请问用n个2*1的小矩形无重
叠地覆盖一个2*n的大矩形，总共有多少种方法？
比如n=3时，2*3的矩形块有3种覆盖方法：

来源：牛客网
链接：https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6
*/
class Solution {
public:
    int rectCover(int number) {
        if(number < 1)
            return 0;
        if(number < 2)
            return 1;
        vector<int> dp(number, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < number; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[number - 1];
    }
};