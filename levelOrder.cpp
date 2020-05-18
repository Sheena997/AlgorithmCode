/*
429. N�����Ĳ������
����һ�� N ������������ڵ�ֵ�Ĳ�������� (�������ң�������)��
���磬����һ�� 3���� :
������������:

[
     [1],
     [3,2,4],
     [5,6]
]
 

˵��:

������Ȳ��ᳬ�� 1000��
���Ľڵ��������ᳬ�� 5000��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> vvc;
        q.push(root);
        if(root == nullptr)
            return vvc;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> vc;
            while(size--)
            {
                Node* cur = q.front();
                q.pop();
                vc.push_back(cur->val);
            
                for(Node* e : cur->children)
                    q.push(e);
            }
            vvc.push_back(vc);
        }
        
        return vvc;
    }
};