class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int i = 0, j = letters.size()-1;
        while(i <= j)
        {
            int m = (i+j)/2;
            if(letters[m] <= target) 
                i = m+1;
            else 
                j = m-1;
        }
        return i < letters.size()? letters[i] : letters[0];
        
    }
};