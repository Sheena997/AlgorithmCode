/*
429. N叉树的层序遍历
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
例如，给定一个 3叉树 :
返回其层序遍历:

[
     [1],
     [3,2,4],
     [5,6]
]
 

说明:

树的深度不会超过 1000。
树的节点总数不会超过 5000。

来源：LeetCode
链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
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