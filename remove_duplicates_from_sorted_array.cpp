/**解题思路：
 * 注意数列是排好序的。
 * 两个指针，第一个指向不重复序列的末一个数，第二个指针向后遍历，直到出现与之前都不同的数，把该数添加到第一个指针后面，并递增第一个指针
 * 该方法会覆盖掉重复的数
 * 
*/

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() < 2) return nums.size();
    int i = 0;
    for(int j = 1; j<nums.size(); j++)
    {
        if(nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}