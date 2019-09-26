class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        //in place

        // ListNode **p, **q;
        if(head == nullptr) return head;
        ListNode **p = &head->next;
        if(head->next == nullptr) return head;
        ListNode *head_even = head->next;
        ListNode **q = &(*p)->next;
        while(*q != nullptr && *p != nullptr)
        {
            *p = *q;
            p = &(*p)->next;
            if(*p)
            {
                *q = *p;
                q = &(*q)->next;
            }

        }
        *p = head_even;
        *q = nullptr;
        return head;
        
    }
};