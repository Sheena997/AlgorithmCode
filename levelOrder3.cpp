/*
102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：LeetCode
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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
        queue<TreeNode*> q;
        
        if(root == nullptr)
            return res;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> vc;
            while(size--)
            {
                TreeNode* tn = q.front();
                q.pop();
                vc.push_back(tn->val);
                
                if(tn->left != nullptr)
                    q.push(tn->left);
                
                if(tn->right != nullptr)
                    q.push(tn->right);
            }
            
            res.push_back(vc);
        }
        
        return res;
    }
};