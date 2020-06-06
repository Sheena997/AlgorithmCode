/*
337. ��ҽ��� III
���ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ��
�µĿ����Եĵ������������ֻ��һ����ڣ����ǳ�֮Ϊ��������
���ˡ�����֮�⣬ÿ����������ֻ��һ��������������֮������һ
�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����
������һ�ö��������� �������ֱ�������ķ�����ͬһ����
�ϱ���٣����ݽ��Զ�������
�����ڲ���������������£�С͵һ���ܹ���ȡ����߽�

ʾ�� 1:

����: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

���: 7 
����: С͵һ���ܹ���ȡ����߽�� = 3 + 3 + 1 = 7.
ʾ�� 2:

����: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

���: 9
����: С͵һ���ܹ���ȡ����߽�� = 4 + 5 = 9.

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/house-robber-iii/
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
      