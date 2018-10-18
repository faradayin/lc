#include <vector>
#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str)
{
    istringstream ins(str);
    char t;
    bool start = false;
    bool sig = true;
    vector<int> s;

    while (ins >> t)
    {
        if (t == ' ' && !start)
            continue;
        else
            start = true;
        if (t == '-' && !start)
        {
            sig = false;
            start = true;
            continue;
        }
        if (t == '+' && !start)
        {
            sig = false;
            start = true;
            continue;
        }
        if(start)
        {
            if (t >= '0' && t <= '9')
                s.push_back(t - '0');
        }

        else
            break;
    }
}
int sum = 0;
for (auto &n : s)
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