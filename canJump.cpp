/*
55. 跳跃游戏
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 
然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。
但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

来源：LeetCode
链接：https://leetcode-cn.com/problems/jump-game/
*/
/*
每个位置都计算自己能达到的最远距离，同时每个位置要判断自己是否可达，
也就是本位置需要在当前最远能到达的距离中。最终计算出来能到达的最远距离，
与数组长度比较即可。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        if(nums.size() <= 1)
            return true;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(i <= maxJump)
                maxJump = max(maxJump, nums[i] + i);
        }
        
        return maxJump >= nums.size() - 1;
    }
};