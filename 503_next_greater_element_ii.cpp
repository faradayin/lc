class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> next(n, -1);
        stack<int> idx;
        for(int i = 0; i < n*2; i++)//遍历两次，第二次遍历不push
        {
            while(!s.empty() && nums[i%n] > nums[idx.top()])
            {
                next[idx.top()] = nums[i%n];
                inx.pop();
                
            }
            if(i<n) idx.push(i);


        }
        return next;

        
    }
};