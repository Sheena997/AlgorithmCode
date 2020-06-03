/*
面试题32 - III. 从上到下打印二叉树 III
请实现一个函数按照之字形顺序打印二叉树，
即第一行按照从左到右的顺序打印，第二层
按照从右到左的顺序打印，第三行再按照从
左到右的顺序打印，其他行以此类推。
例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
 

提示：
节点总数 <= 1000


来源：LeetCode
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> ret;
            while(size--)
            {
                TreeNode* valNode = q.front();
                q.pop();
                ret.push_back(valNode->val);
                if(valNode->left)
                    q.push(valNode->left);
                if(valNode->right)
                    q.push(valNode->right);
            }
            if((i & 1) == 0)
                reverse(ret.begin(), ret.end());
            res.push_back(ret);
            ++i;
        }
        
        return res;
    }
};