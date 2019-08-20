/**解题思路：
 * 该题方法比较直观，但是需要考虑的细节相当麻烦。本人开始运用的方法，首先要考虑两个链表都为空的情况，此时返回空指针；
 * 如果任一链表非空，则要运用while循环进行归并；
 * 关键点在归并后，如何获得链表的头指针并返回呢？
 * pezy的方法，运用节点指针的指针 p,初始时p指向空的head指针，在归并过程中，p指向尾节点的next域
 * 通过操作*p,即可实现链表的延长,而头指针始终是指向链表第一个节点
 * 注意解引用 * 优先级是低于 -> 的，所以正确的写法： *p = &(*p)->next
*/



//pezy的方法，运用指针的指针，避免了头指针的问题
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *header = NULL, **p;
    for (p = &header; l1 && l2; p = &(*p)->next)
    {
        if (l1->val <= l2->val)
        {
            *p = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            *p = new ListNode(l2->val);
            l2 = l2->next;
        }
    }
    for (ListNode *leave = l1 ? l1 : l2; leave; leave = leave->next, p = &(*p)->next)
        *p = new ListNode(leave->val);
    return header;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *header = nullptr;
    ListNode **p;
    for(p = &header; l1 && l2; p = &(*p)->next)
    {
        if(l1->val < l2->val)
        {
            *p = new ListNode(l1->val);
            l1 = l1->next;
        }
        else 
        {
            *p = new ListNode(l2->val);
            l2 = l2->next;
        }
    }
    
    for(ListNode *last = l1? l1 : l2; last; last = last->next)
    {
        *p = new ListNode(last->val);
        p = &(*p)->next;
    }
    return header;
}
//仿pezy，正确的代码
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *head = nullptr, **p = &head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            *p = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            *p = new ListNode(l2->val);
            l2 = l2->next;
        }

        p = &(*p)->next;
    }
    while (l1)
    {
        *p = new ListNode(l1->val);
        l1 = l1->next;
        p = &(*p)->next;
    }
    while (l2)
    {
        *p = new ListNode(l2->val);
        l2 = l2->next;
        p = &(*p)->next;
    }
    return head;
}

//递归的方法
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l2 == nullptr) return l1;
    if(l1 == nullptr) return l2;

    if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    else 
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2
        }
}
