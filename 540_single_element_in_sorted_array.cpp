class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int i = 0, j = nums.size()-1;
        while(i < j)
        {
            int m = (i+j)/2;
            if(nums[m] != nums[m-1] && nums[m] != nums[m+1]) return nums[m];
            if(m%2 == 0 && nums[m] == nums[m-1])//m为偶数,等于左边
                j = m;
            else if(m%2 == 0 && nums[m] == nums[m+1])
                i = m;
            else if(m%2 == 1 && nums[m] == nums[m-1])//m为奇数，等于左边
                i = m+1;
            else if(m%2 == 1 && nums[m] == nums[m+1])
                j = m-1;
        }
        return nums[i];
        
    }
};