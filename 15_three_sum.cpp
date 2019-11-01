/***解题思路
 * 主要思想是固定一个数，然后利用“夹逼”的思想，搜索另外两个数。
 * 夹逼：要求是在排序的数组上，根据和的大小，调整前后两个指针；front递增，两数之和增加，back递减，两数之和减小；如此在线性时间内即可搜寻到和为固定值的两个数
 * 避免重复：要求结果的triplet不能重复，注意，这里triplet之内是可以有相同值的，因为给定的数组内就有相同的数；
 * 避免得到相同triplet的去重方法：如果下标递增后的数与原来的数相同，则继续递增下标（利用while循环），跳过与之前相同的数
 * 另外一个重要的地方：要注意边界！尤其是跳过相同值时，要考虑到，不能超过数组边界，且要时刻保证front<back
*/
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> r;
    if (nums.size() < 3)
        return r;
    sort(nums.begin(), nums.end());

    for (size_t n1 = 0; n1 < nums.size() - 2;)
    {

        size_t n2 = n1 + 1;
        size_t n3 = nums.size() - 1;

        while (n2 < n3)
        {
            if (nums[n1] + nums[n2] + nums[n3] == 0)
            {
                r.push_back(vector<int>({nums[n1], nums[n2], nums[n3]}));
                n2++;
                while (n2 < n3 && nums[n2] == nums[n2 - 1])
                    n2++;
                n3--;
                while (n2 < n3 && nums[n3] == nums[n3 + 1])
                    n3--;
            }

            else if ((nums[n1] + nums[n2] + nums[n3]) < 0)
            {
                n2++;
                while (n2 < n3 && nums[n2] == nums[n2 - 1])
                    n2++;
            }

            else
            {
                n3--;
                while (n2 < n3 && nums[n3] == nums[n3 + 1])
                    n3--;
            }
        }
        n1++;
        while (n1 < nums.size() - 2 && nums[n1] == nums[n1 - 1])
            n1++;
    }
    return r;
}

//也可以用set<vector<int>>来避免重复
vector<vector<int>> three_Sum(vector<int> &nums)
{
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (!nums.empty() && nums.back() < 0)
        return {};
    for (int k = 0; k < nums.size(); ++k)
    {
        if (nums[k] > 0)
            break;
        int target = 0 - nums[k];
        int i = k + 1, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                res.insert({nums[k], nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1])
                    ++i;
                while (i < j && nums[j] == nums[j - 1])
                    --j;
                ++i;
                --j;
            }
            else if (nums[i] + nums[j] < target)
                ++i;
            else
                --j;
        }
    }
    return vector<vector<int>>(res.begin(), res.end());
}
int main()
{
    vector<int> t = {-1, 0, 1, 2, -1, -4};
    auto r = three_Sum(t);
    for (auto &ele : r)
    {
        for (auto &n : ele)
            cout << n << '\t';
        cout << endl;
    }
}