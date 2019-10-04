class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa && pb) 
        {
            pa = pa->next;
            pb = pb->next;
        }
        
        ListNode* p = nullptr, *q = nullptr;
        if(pa) {p = headA;q = headB;}
        else if(pb) {p = headB;q = headA;}
        else {p = headA;q = headB;}
        ListNode *pc = pa? pa : pb;
        int c = 0;
        while(pc)
        {
            c++;
            pc = pc->next;
        }
        while(c--)
        {
            p = p->next;
        }
        while(p != q)
        {
            p = p->next;
            q = q->next;
        }
        return p;  
    }
};