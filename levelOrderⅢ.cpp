/*
������32 - III. ���ϵ��´�ӡ������ III
��ʵ��һ����������֮����˳���ӡ��������
����һ�а��մ����ҵ�˳���ӡ���ڶ���
���մ��ҵ����˳���ӡ���������ٰ��մ�
���ҵ�˳���ӡ���������Դ����ơ�
����:
����������: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
�������α��������

[
  [3],
  [20,9],
  [15,7]
]
 

��ʾ��
�ڵ����� <= 1000


��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
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