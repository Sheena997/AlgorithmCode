/*
������ 04.12. ���·��
����һ�ö�����������ÿ���ڵ㶼����һ��������ֵ(��ֵ������)�����һ���㷨����ӡ�ڵ���ֵ�ܺ͵���ĳ������ֵ������·����������ע�⣬·����һ���ǵôӶ������ĸ��ڵ��Ҷ�ڵ㿪ʼ������������䷽���������(ֻ�ܴӸ��ڵ�ָ���ӽڵ㷽��)��

ʾ��:
�������¶��������Լ�Ŀ��� sum = 22��

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
����:

3
���ͣ���Ϊ 22 ��·���У�[5,4,11,2], [5,8,4,5], [4,11,7]
��ʾ��

�ڵ����� <= 10000

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/paths-with-sum-lcci/
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
    int res = 0;
    
    void dfs(TreeNode* root, int sum, int cur)
    {
        if(root == nullptr)
            return;
        
        cur += root->val;
        if(cur == sum)
            ++res;
        
        if(root->left)
            dfs(root->left, sum, cur);
        if(root->right)
            dfs(root->right, sum, cur);
    }
    void _pathSum(TreeNode* root, int sum)
    {
        if(root == nullptr)
            return;
        
        int cur = 0;
        dfs(root, sum, cur);
        
        _pathSum(root->left, sum);
        _pathSum(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        _pathSum(root, sum);
        
        return res;
    }
};