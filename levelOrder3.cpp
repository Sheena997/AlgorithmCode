/*
102. �������Ĳ������
����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
ʾ����
��������[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
�������α��������

[
  [3],
  [9,20],
  [15,7]
]

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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