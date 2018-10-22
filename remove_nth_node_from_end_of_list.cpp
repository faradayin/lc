/**解题思路：遍历的过程中构造一个数组，存储每个节点的指针
 * 关键点是，要区分删除的是尾节点和头节点的情况
*/
//边界！！
class Solution 
{
public:
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    vector<ListNode*> po;
    ListNode* p = head;
    //po.push_back(p);
    while(p != NULL)
    {
        po.push_back(p);
        p = p->next;
    }
    if(n == 1 && n != po.size())
        po[po.size()-n-1]->next = NULL;
    else if (n == po.size())
        head = po[po.size()-n]->next;
    else 
        po[po.size()-n-1]->next = po[po.size()-n]->next;
    delete po[po.size()-n];
    return head;

}

};