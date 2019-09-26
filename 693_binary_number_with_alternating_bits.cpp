class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        long n1 = n >> 1;
        long res = n1 ^ n;//res should be ...1111
        //res & (res + 1) should be ...0000
        //or:
        // 0111 1111
        // 1000 0000  ^
        //_________________
        // 0000 0000

        return (res & (res + 1)) == 0;
        
    }
};