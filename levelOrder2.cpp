/*
面试题32 - I. 从上到下打印二叉树
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
例如:
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回：
[3,9,20,15,7]
 
提示：
节点总数 <= 1000
来源：LeetCode
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> vc;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        if(root == nullptr)
            return vc;
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* tq = q.front();
                q.pop();
                vc.push_back(tq->val);
                
                if(tq->left != nullptr)
                    q.push(tq->left);
                
                if(tq->right != nullptr)
                    q.push(tq->right);
            }
        }
        
        return vc;
    }
};