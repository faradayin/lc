/**解题思路：
 * 用被除数不断减去除数，商就是减去的次数；
 * temp增长的幅度是指数的，通过左移运算符实现
 * 
 * 溢出的情况：divisor == 0 || (dividend == INT_MIN && divisor == -1)
 *  
 * 
*/
int divide(int dividend, int divisor)
{
    if (!divisor || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    int res = 0;
    while (dvd >= dvs)
    {
        long long temp = dvs;
        long long mc = 1;
        while(dvd >= temp<<1)
        {
            temp <<= 1;
            mc <<= 1;
        }
        res += mc;
        dvd -= temp;
    }
    return sign == 1 ? res : -res;
}