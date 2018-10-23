/**解题思路：
 * 类似于“three sum”，首先排序，然后固定first；second和third首位夹逼
 * 比较简单
*/

int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());

    int md = dis(nums[0]+nums[1]+nums[-1], target);
    int sum = nums[0]+nums[1]+nums[nums.size()-1];//虽然数组下标可以是负数，但不能越界

    for(size_t i = 0;i < nums.size()-2; i++)
    {
        size_t j = i+1;
        size_t k = nums.size()-1;

        while(j < k)
        {
            if(nums[i]+nums[j]+nums[k] == target)
                return target;
            else
            {   
                if(md > dis(nums[i]+nums[j]+nums[k], target))
                {
                    sum = nums[i]+nums[j]+nums[k];
                    md = dis(nums[i]+nums[j]+nums[k], target);
                }
 

                if(nums[i]+nums[j]+nums[k] < target)
                    j++;
                else 
                    k--;

            }

        }
        
    }
    return sum;
}

int dis(int x, int y)
{
    if(x < y)
        return y-x;
    else 
        return x-y;
}