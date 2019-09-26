class Solution {
    int cnt = 0;
    void extend_at(string &s, int i, int j)
    {
        char val = s[i];
        while(i >= 0 && j <= s.size()-1)
        {
            if(s[i] == val && s[i] != s[j]) cnt++;
            else break;
            i--;
            j++;
        }
    }
public:
    int countBinarySubstrings(string s) 
    {
        for(int i=0; i < s.size()-1; i++)
        {
            extend_at(s, i, i+1);
        }
        return cnt;
    }
};