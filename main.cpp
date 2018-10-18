#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x == 0)
        return true;
    vector<int> xx;
    while (x != 0)
    {
        xx.push_back(x % 10);
        x /= 10;
    }
    auto it_a = xx.begin();
    auto it_b = xx.end();
    it_b--;
    while (it_a < it_b)
    {
        if (*it_a != *it_b)
            return false;
        it_a++;
        it_b--;
    }
    return true;
}

int main()
{
    int num = 121121;
    
    cout << (isPalindrome(num)? "yes": "no") << endl;

    return 0;
}