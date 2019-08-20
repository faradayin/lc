class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* h, int k) 
    {
        vector<ListNode*> l;
        while(h != nullptr)
        {
            l.push_back(h);
            h = h->next;
        }

        while(l.size() < k)
            l.push_back(nullptr);

        int n = l.size();
        vector<ListNode*> res;
        int step = n/k;
        int tail = n%k;
        int idx = 0;
        for(int i=0; i < k; i++)
        {
            res.push_back(l[idx]);
            if(tail != 0)
            {
                idx += (step + 1);
                tail--;
            }
            else
            {
                idx += step;
            }
            if(l[idx-1]) l[idx-1]->next = nullptr;
        }
        return res;
    }
};