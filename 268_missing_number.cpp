class Solution {
public:
    int missingNumber(vector<int>& nums)
     {
         int tot = nums.size()*(nums.size()+1)/2;
         for(int n: nums) tot -= n;
         return tot;
        
    }
};

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        //利用 x ^ x = 0
        int res = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            res = res ^ i ^ nums[i];
        }
        res = res ^ nums.size();//一共n+1个数
        return  res;
    }


};