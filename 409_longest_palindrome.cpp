class Solution {
public:
    int longestPalindrome(string s) 
    {
        vector<int> m(256, 0);
        for(auto c: s)
        {
            m[c-'\0']++;
        }
        int res = 0;
        bool odd_exist = false;
        for (auto n: m)
        {
            if(n % 2 == 0) res += n;//偶数
            else
            {
                odd_exist = true;
                res +=(n-1);
            }

        }
        if(odd_exist) ++res;
        return res;
        
    }
};