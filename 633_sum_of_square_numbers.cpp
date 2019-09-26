class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        //使用long，否则会溢出
        long i = 0;
        long j = (long) sqrt(c);
        while(i <= j)
        {
            long val = i*i + j*j;
            if(val == c ) return true;
            if(val > c) j--;
            else i++;
        }
        return false;
    }
};