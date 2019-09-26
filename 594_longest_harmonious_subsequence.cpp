class Solution {
public:
// 应该注意的是序列的元素不一定是数组的连续元素
    int findLHS(vector<int>& nums) 
    {
        map<int, int> m;
        for(auto &n : nums)
        {
            ++m[n];
        }
        int max = 0;
        for(auto &p : m)
        {
            if(m.count(p.first+1))
            max = max > m[p.first]+m[p.first+1] ? max: m[p.first]+m[p.first+1];

        }
        return max;
    }
};