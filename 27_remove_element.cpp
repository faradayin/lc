/**解题思路：两个指针，一快一慢，可以拟人化的考虑
 * 当 j != val 时，递增 j
 * 当 j == val 时， n[i] = n[j]，然后 i + 1，继续递增 j
 * 直到 j到末尾，此时 i 即为当前不含val的数列末尾
*/
int removeElement(vector<int>& nums, int val)
{
    int i = 0;
    for(int j = 0; j < nums.size(); j++)
    {
        if(nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    retun i;
}