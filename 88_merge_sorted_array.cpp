class Solution {
public://only you
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) 
    {
        int tend =  m+n-1;
        int i = m-1, j = n-1;
        while(tend >= 0 )
        {
            if(i<0)
            {
                while(j >= 0)
                {
                    n1[tend--] = n2[j--];
                }
                break;
            }
            else if(j<0)
            {
                while(i >= 0)
                {
                    n1[tend--] = n1[i--];
                }
                break;
            }  
            if(n1[i] >= n2[j]) 
            {
                n1[tend--] = n1[i--];
            }
            else
            {
                n1[tend--] = n2[j--];
            }

        }

    }
};