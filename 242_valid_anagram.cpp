class Solution {
public:
    bool isAnagram(string s, string t) {
        int m[26] = {0};
        for(auto c: s)
        {
            m[c-'a'] ++;

        }
        for(auto c: t)
        {
            m[c-'a'] --;
        }
        for(int i=0; i<26; i++)
        {
            if(m[i] != 0)
                return false;
        }
        return true;
    }
};