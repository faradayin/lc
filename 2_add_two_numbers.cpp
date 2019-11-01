/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        
        ListNode* r=new ListNode(0);
        ListNode* rp = r, *last = rp;//last保存上一个节点指针
        int sum = 0;
        while(l1 || l2)
        {
            rp->next = new ListNode(0);
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
                
            }
            
            rp->val = sum%10;
            sum = sum/10;
            last = rp;
            rp = rp->next;
            
            
        }
        if(sum)
            rp->val = sum;
        else
        {
            delete rp;//释放内存
            last->next = NULL;
        }
        return r;        
    }
};