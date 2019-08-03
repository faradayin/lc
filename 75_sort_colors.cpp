class Solution {
public:
//count sort
    void sortColors(vector<int>& nums) 
    {
        vector<int> m(3,0);
        for(auto i:nums)
        {
            m[i]++;
        }
        int p = 0;
        for(int j=0;j<3;j++)
        {
            for(int jj=0;jj<m[j];jj++)
                nums[p++] = j;

        }
        
    }
};