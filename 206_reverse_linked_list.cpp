// 刷题的目的:
// practice makes perfect

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* next = head->next;//这里先保存相邻节点的指针
        ListNode* new_head = reverseList(next);
        next->next = head;
        head->next = nullptr;
        return new_head;
    }
};