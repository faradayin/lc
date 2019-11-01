vector<int> searchRange(vector<int>& nums, int target)
{
    int l = 0, r = nums.size()-1;
    vector<int> res;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(nums[m] == target)
        {
            int left = m, right = m;

            while(left-1 >= 0 && nums[left-1] == target) left--;
            res.push_back(left);
            while(right+1 <= nums.size()-1 && nums[right+1] == target) right++;
            res.push_back(right);
            return res;

        }
        if(nums[m] < target)
        {
            l = m+1;
        }
        else //nums[m] > target
        {
            r = m-1;
        }


    }
    res = {-1, -1};
    return res;

}