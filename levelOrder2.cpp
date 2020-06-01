/*
������32 - I. ���ϵ��´�ӡ������
���ϵ��´�ӡ����������ÿ���ڵ㣬ͬһ��Ľڵ㰴�մ����ҵ�˳���ӡ��
����:
����������: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
���أ�
[3,9,20,15,7]
 
��ʾ��
�ڵ����� <= 1000
��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
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