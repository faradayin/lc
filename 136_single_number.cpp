class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        // 两个相同的数异或的结果为 0，对所有数进行异或操作，最后的结果就是单独出现的那个数
        int res = 0;
        for(int n: nums) res = res ^ n;
        return res;
        
    }
};