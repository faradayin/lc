//使用额外的空间
class Solution {
public:
    bool isPalindrome(int x) 
    {
        bool res = true;
        int val = x;
        vector<int> s;
        while(val)
        {
            s.push_back(val%10);
            val /= 10;
        }
        for(int i=0, j=s.size()-1; i < j; i++, j--)
        {
            if(s[i] != s[j])
            {
                res = false;
                break;
            }
        }
        return res;
    }
};

//不使用额外的空间
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x == 0) return true;
        if(x < 0 || x%10 == 0) return false;//末尾为0
        int right = 0;
        while(x > right)
        {
            right = right * 10 + x % 10;
            x /= 10;
        }
        return x == right || x == right / 10;
    }

};