/*
���ӣ�https://www.nowcoder.com/questionTerminal/b58434e200a648c589ca2063f1faf58c
��Դ��ţ����

[�����]������ָ�����䷴ת
�ȶ�ָ����20344ʱ�����ƣ�C/C++ 1�룬��������2��ռ����ƣ�C/C++ 32M����������64M
�㷨֪ʶ��Ƶ����
��һ������\ m m λ�õ�\ n n λ��֮������䷴ת��Ҫ��ʱ�临�Ӷ� ���ռ临�Ӷ� ��
���磺
����������Ϊ 1\to 2 \to 3 \to 4 \to 5 \to NULL1��2��3��4��5��NULL, ��,
���� 1\to 4\to 3\to 2\to 5\to NULL1��4��3��2��5��NULL.
ע�⣺
������ ��������������
1 \leq m \leq n \leq ������1��m��n��������
ʾ��1
����
{1,2,3,4,5},2,4
���
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
     * @param head ListNode�� 
     * @param m int���� 
     * @param n int���� 
     * @return ListNode��
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