/**
 * 总以为时间流逝是一件稀松平常的事。真当一切逝去，你空在寂寞里感叹
*/
void nextPermutation(vector<int>& nums)
{
    if(nums.size() <= 1) return;//至少要两个元素
    int i = nums.size()-1;
    while(i != 0 && nums[i] <= nums[i-1]) i--;
    if(i == 0)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    //此时至少3个元素
    int j = i-1;
    while(i+1 < nums.size() && nums[i+1] > nums[j]) i++;
    int t = nums[j];
    nums[j] = nums[i];
    nums[i] = t;
    sort(nums.begin()+j+1, nums.end());
    return;
}
