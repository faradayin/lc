/**解题思路：运用指针的指针，直接操纵链表中的next域；
 * 然后注意链表之间的断开、连接先后顺序，一般在断开一条链之前，用一个临时量存储下一节点的地址
 * 
*/


ListNode* swapPairs(ListNode* head)
{
    if(!(head && head->next))
        return head;
    ListNode **h = &head;
    //head = head->next;
    do
    {
        auto *p = *h;
        *h = (*h)->next;
        auto *t = (*h)->next;
        (*h)->next = p;
        p->next = t;
        h = &(p->next);
    }
    while(*h && (*h)->next);
    return head;

}