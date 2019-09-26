class Solution {
public:
    bool isSubsequence(string s, string t) {
        //s is sub of t
        int is = 0;
        int it = 0;
        for(; is < s.size(); is++)
        {
            while(s[is] != t[it] && it != t.size())  it++;
            if(it == t.size()) return false;
            it++;

        }
        return true;
    }
};