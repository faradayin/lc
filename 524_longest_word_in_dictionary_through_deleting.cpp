class Solution {
public:
    string findLongestWord(string s, vector<string>& d)
    {
        string res; 
        for(auto ds : d)
        {
            if(ds.size()>s.size()) continue;
            if(substr(s, ds) && ds.size() >= res.size())
            {   
                if(ds.size() == res.size())
                    res = res<ds? res:ds;
                else
                {
                    res = ds;
                }

            }

        }
        return res;

        
    }
private:
    bool substr(string s, string sub)
    {
        int i = 0, j = 0;
        while (i != s.size() && j != sub.size())
        {
            if(s[i] == sub[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }

        }
        if(j == sub.size()) return true;
        return false;
        
    }
};
// find the longest string in the dictionary 
// that can be formed by deleting some characters of the given string. 
// If there are more than one possible results, 
// return the longest word with the *smallest* lexicographical order. 


