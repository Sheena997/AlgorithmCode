/*
链接：https://www.nowcoder.com/questionTerminal/b58434e200a648c589ca2063f1faf58c
来源：牛客网

[编程题]链表内指定区间反转
热度指数：20344时间限制：C/C++ 1秒，其他语言2秒空间限制：C/C++ 32M，其他语言64M
算法知识视频讲解
将一个链表\ m m 位置到\ n n 位置之间的区间反转，要求时间复杂度 ，空间复杂度 。
例如：
给出的链表为 1\to 2 \to 3 \to 4 \to 5 \to NULL1→2→3→4→5→NULL, ，,
返回 1\to 4\to 3\to 2\to 5\to NULL1→4→3→2→5→NULL.
注意：
给出的 满足以下条件：
1 \leq m \leq n \leq 链表长度1≤m≤n≤链表长度
示例1
输入
{1,2,3,4,5},2,4
输出
{1,4,3,2,5}
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(head == nullptr)
            return nullptr;
        
        ListNode* list = new ListNode(-1);
        list->next = head;
        ListNode *pre, *start = head;
        for(int i = 1; i < m; ++i)
        {
            pre = start;
            start = start->next;
        }
        for(int i = m; i < n; ++i)
        {
            ListNode* tmp = start->next;
            start->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        
        return list->next;
    }
};