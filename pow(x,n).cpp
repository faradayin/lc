class Solution {
public:

//solution from pezy
    double pow(double x, int n) {
        if (!n) return 1;
        double tmp = pow(x, n/2);
        return n&0x1 ? n>0 ? x * tmp * tmp : tmp * tmp / x : tmp * tmp;
    }

//solution from discussion
    double myPow(double x, int n)
    {
        double ans = 1;
        unsiged long p;
        if(n < 0)
        {
            p = -n;
            x = 1/x;
        }
        else   
            p = n;
        while(p)
        {
            if(p&1)
                ans *= x;
            x *= x;
            p >>=1;
        }
        return ans;

    }
};