#include <vector>
#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str)
{
    bool start = false;
    bool sig = true;
    vector<int> s;
    int sum = 0;
    for(auto &t: str)
    {
        if (t == ' ' && !start)
            continue;

        if (t == '-' && !start)
        {
            sig = false;
            start = true;
            continue;
        }
        if (t == '+' && !start)
        {
            sig = true;
            start = true;
            continue;
        }

        if (t >= '0' && t <= '9')
        {
            s.push_back(t - '0');
            start = true;
        }
            
        else 
            break;
        


    }


    for (auto &n : s)//s可以是空的
    {
        if (sig)
        {
            if (sum < INT_MAX / 10 || (sum == INT_MAX / 10 && n <= INT_MAX % 10))
                sum = sum * 10 + n;
            else
                return INT_MAX;
        }
        else
        {
            if (sum > INT_MIN / 10 || (sum == INT_MIN / 10 && n <= INT_MAX % 10))
                sum = sum * 10 - n;
            else
                return INT_MIN;
        }
    }
    return sum;
}