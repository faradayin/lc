class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // O(1) space
        // diff & (-diff);  // 得到最右一位
        // diff & (diff - 1) //去除最低一位
        int diff = 0;
        for(int n: nums) diff = diff ^ n;
        diff = diff ^ (-diff);
        vector<int> res(2, 0);
        for(int n: nums)
        {
            if((n & diff) == 0) res[0] = res[0] ^ n;
            else res[1] = res[1] ^ n;
        }
        return res;
    }
};