class Solution {
public:
    string reverseVowels(string s) 
    {
        if(s.size() <= 1) return s;
        unordered_set<char> v = {'a','e','i','o','u','A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = s.size()-1;
        while(i<j) 
        {
            if(!v.count(s[i])) 
            {
                i++;
                continue;
            }
            if(!v.count(s[j]))
            {
                j--;
                continue;
            }
            //swap
            {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
            i++;
            j--;

        }
        return s;
    }
};