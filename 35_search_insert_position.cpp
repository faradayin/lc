/**这道easy，二分搜索，可最后如何确定插入点？
 * 直接返回 l 即可，也是醉了
 * 
*/
int searchInsert(vector<int>& nums, int target)
{
    int l = 0, r = nums.size()-1;
    int m;
    while(l <= r)
    {
        m = (l+r)/2;
        if(nums[m] == target) return m;
        if(target < nums[m])
        {
            r = m-1;
        }
        else // target > nums[m]
        {
            l = m+1;
        }
    }

    return l;
}