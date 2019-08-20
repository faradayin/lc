//要坚信题是可解的，坚信C++能够解决
//深究！！！
//总结答案里的编程思想
//重构
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        helper(head, head);
        return answer;
    }

private:
    bool answer = true;
    void helper(ListNode* &left, ListNode* &right)
    {
        if(right != nullptr)
        {
            helper(left, right->next);
            if(left->val != right->val)
            {
                answer = false;
                return;
            }
            //如果该元素是满足回文要求的，这里改变left引用指向的值，然后返回上层调用，判定上一个元素是不是满足
            else 
            {
                left = left->next;
                return;
            }
        }
    }
};