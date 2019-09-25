//字符串同构
// No two characters may map to the same character but a character may map to itself
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size() != t.size()) return false;
        vector<int> m(256, 0);
        vector<int> used(256, 0);//防止一个字母被多个字母映射
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(m[c] != 0)
            {
                if(t[i] != m[c]) return false;
            }
            else//c没出现过
            {
                if(used[t[i]] == 0)
                {
                    m[c] = t[i];
                    used[t[i]] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};
//方法二
//两个字符串对应位置的字母，应该在同一个位置i上出现
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        vector<int> occ_at_s(256, 0);
        vector<int> occ_at_t(256, 0);
        for(int i = 0; i < s.size(); i++)
        {
            if(occ_at_s[s[i]] != occ_at_t[t[i]]) return false;
            occ_at_s[s[i]] = i+1;
            occ_at_t[t[i]] = i+1;
        }
        return true;

    }

};