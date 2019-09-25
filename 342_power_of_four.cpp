class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        // 这种数在二进制表示中有且只有一个奇数位为 1
        return num > 0 && (num & (num-1)) == 0 && (num & 0b01010101010101010101010101010101) != 0;
        
    }
};