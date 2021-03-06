/*
337. 打家劫舍 III
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个
新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一
番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列
类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚
上被打劫，房屋将自动报警。
计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

来源：LeetCode
链接：https://leetcode-cn.com/problems/house-robber-iii/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
    vector<int> dfs(TreeNode* root)
    {
        if(!root)
            return vector<int>(2, 0);
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> res(2);
        res[0] = left[1] + right[1] + root->val;
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);
        
        return res;
    }
};
      