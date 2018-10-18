#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    if (nums.size() < 4)
        return res;
    sort(nums.begin(), nums.end());
    for (size_t n1 = 0; n1 < nums.size() - 3;)
    {

        for (size_t n2 = n1 + 1; n2 < nums.size() - 2;)
        {
            
            size_t n3 = n2 + 1;
            size_t n4 = nums.size() - 1;

            while (n3 < n4)
            {
                if (nums[n1] + nums[n2] + nums[n3] + nums[n4] == target)
                {
                    res.push_back(vector<int>({nums[n1], nums[n2], nums[n3], nums[n4]}));
                    n3++;
                    while (n3 < n4 && nums[n3] == nums[n3 - 1])
                        n3++;
                    n4--;
                    while (n3 < n4 && nums[n4] == nums[n4 + 1])
                        n4--;
                }
                else if (nums[n1] + nums[n2] + nums[n3] + nums[n4] < target)
                {
                    n3++;
                    while (n3 < n4 && nums[n3] == nums[n3 - 1])
                        n3++;
                }
                else
                {
                    n4--;
                    while (n3 < n4 && nums[n4] == nums[n4 + 1])
                        n4--;
                    
                }

            }
            n2++;
            while(n2<nums.size() - 2 && nums[n2]==nums[n2-1]) n2++;


        }
        n1++;
        while(n1 < nums.size() - 3 && nums[n1] == nums[n1-1]) n1++;
    }
    return res;
}