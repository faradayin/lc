class Solution {
private:
    int forward(unordered_map<int, int>& m, int n)
    {
        if(! m.count(n)) return 0;
        int cnt = m[n];
        if(cnt > 1) return cnt;
        //这里递归
        cnt = forward(m, n+1) + 1;
        m[n] = cnt;
        return cnt;

    }
    int maxCount(unordered_map<int, int>& m)
    {
        int ma = 0;
        for(auto p: m)
            ma = max(ma, p.second);
        return ma;
    }
public:
// 要求以 O(N) 的时间复杂度求解
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &n:nums) m[n] = 1;
        for(auto &n:nums) forward(m, n);
        return maxCount(m);

    }
};