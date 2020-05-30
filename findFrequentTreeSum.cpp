/*
508. 出现次数最多的子树元素和
给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。
一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，
返回所有出现次数最多的子树元素和（不限顺序）。
示例 1：
输入:

  5
 /  \
2   -3
返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
示例 2：
输入：

  5
 /  \
2   -5
返回 [2]，只有 2 出现两次，-5 只出现 1 次。

来源：LeetCode
链接：https://leetcode-cn.com/problems/most-frequent-subtree-sum/
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
    int dfs(unordered_map<int, int>& unmp, int& max_sum, TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l_sum = dfs(unmp, max_sum, root->left);
        int r_sum = dfs(unmp, max_sum, root->right);
        int ret = root->val + l_sum + r_sum;
        
        max_sum = max(++unmp[ret], max_sum);
        
        return ret;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> unmp;
        int max_sum = INT_MIN;
        
        int ret = dfs(unmp, max_sum, root);
        
        vector<int> res;
        for(auto& e : unmp)
        {
            if(max_sum == e.second)
                res.push_back(e.first);
        }
        
        return res;
    }
};