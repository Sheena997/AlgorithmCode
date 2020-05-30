/*
508. ���ִ�����������Ԫ�غ�
����һ���������ĸ���㣬�����ҳ����ִ�����������Ԫ�غ͡�
һ�����ġ�����Ԫ�غ͡�����Ϊ�Ըý��Ϊ���Ķ����������н���Ԫ��֮�ͣ�������㱾����
����Ҫ���س��ִ�����������Ԫ�غ͡�����ж��Ԫ�س��ֵĴ�����ͬ��
�������г��ִ�����������Ԫ�غͣ�����˳�򣩡�
ʾ�� 1��
����:

  5
 /  \
2   -3
���� [2, -3, 4]�����е�ֵ��ֻ����һ�Σ�������˳�򷵻�����ֵ��
ʾ�� 2��
���룺

  5
 /  \
2   -5
���� [2]��ֻ�� 2 �������Σ�-5 ֻ���� 1 �Ρ�

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/most-frequent-subtree-sum/
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