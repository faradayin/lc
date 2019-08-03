class Solution {
private:
    int cnt = 0;

    void extend_at(string &s, int i, int j)
    {
        while(i>=0 && j<s.size())
        {
            if(s[i] != s[j]) break;
            cnt++;
            i--;
            j++;
        }
    }

public:
    int countSubstrings(string s) {
        for(int i=0; i<s.size(); i++)
        {
            extend_at(s, i, i);
            extend_at(s, i, i+1);
        }
        return cnt;
    }
};