/*
1043. 分隔数组以得到最大和
给出整数数组 A，将该数组分隔为长度最多为 K 
的几个（连续）子数组。分隔完成后，每个子数
组的中的值都会变为该子数组中的最大值。
返回给定数组完成分隔后的最大和。
示例：
输入：A = [1,15,7,9,2,5,10], K = 3
输出：84
解释：A 变为 [15,15,15,9,10,10,10]
提示：
1 <= K <= A.length <= 500
0 <= A[i] <= 10^6

来源：LeetCode
链接：https://leetcode-cn.com/problems/partition-array-for-maximum-sum/
*/
/*
对于数组求 最大  最小问题 一般为 动态规划问题
建立一位数组dp dp[i] 表示：从 0 到 位置 i 子数组的最大和
    对于每一个位置 都可能有 k 种情况：
         ①：只使用它自己位置的数字
         ②：让他保持和前面 1 个数字相同
         ........
         ⑩：让他保持和前面 k - 1 个数字相同
    转移方程：
         ①：domainMax = Math.max(domainMax, A[i - j + 1]);
            作用：求它和前面 j - 1 个数字的最大值 为保持相同的数字
         ②：dp[i] = Math.max(dp[i], ((i - j < 0)? 0 : dp[i - j])  + j * domainMax);
            作用：求位置 i 的时候 k 种情况 的最大值
    边界条件：
         ①：i - j + 1 >= 0
            作用：保证它的前面有 j - 1 个元素
         ②：i - j < 0？
            作用：判断 当 前面恰有 j - 1 个元素 且 第 i 个位置 保持和前面 j - 1 个数字相同
*/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i)
        {
            int maxVal = INT_MIN, j = i, k = 0;
            while(k < K && j >= 0)
            {
                maxVal = max(maxVal, A[j]);
                dp[i] = max(dp[i], (j == 0 ? 0 : dp[j - 1]) + maxVal * (i - j + 1));
                ++k;
                --j;
            }
        }
        
        return dp[n - 1];
    }
};

