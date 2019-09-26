//排序方法
class Solution {
public:
//欺骗自己的人最可悲

    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
        
    }
};

// 堆。维护一个长度为K的最小堆，这样堆顶元素为第K大元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int> > pq; //min_heap
        for(int val : nums)
        {
            pq.push(val);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
// 自己没有追求，自己没有毅力，就不要怪别人没帮你创造条件，不要怪别人没提醒你

// 快选
// quick select 
// O(N)复杂度
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        
    }
};
