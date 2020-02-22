/*
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约
请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
注意：本题相对原题稍作改动
示例 1：
输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
示例 2：
输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
示例 3：
输入： [2,1,4,5,3,1,1,3]
输出： 12
解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-masseuse-lcci
*/
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size());
        
        dp[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            int j = i - 1;
            while(j >= 0)
            {
                int tmp = (j - 1 >= 0) ? dp[j - 1] : 0;
                dp[i] = max(dp[i], tmp + nums[i]);
                --j;
            }
            
            res = max(dp[i], res);
        }
        
        return res;
    }
};