//动态规划
// imax[i] = max( imax[i]*a[i], a[i] )
// 注意:遇到负数，最大变最小，最小变最大
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> imax(n);
        vector<int> imin(n);
        imax[0] = imin[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i] >= 0)
            {
                imax[i] = max(imax[i-1]*nums[i], nums[i]);
                imin[i] = min(imin[i-1]*nums[i], nums[i]);
            }
            else 
            {
                imax[i] = max(imin[i-1]*nums[i], nums[i]);
                imin[i] = min(imax[i-1]*nums[i], nums[i]);
            }
        }
        int res = imax[0];
        for(int i=1; i<n; i++) res = res >= imax[i]? res : imax[i];
        return res;
    }
};

//重构
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int res = nums[0];//global opt
        int imax = res, imin = res;
        for(int i=1; i<n; i++)
        {
            if(nums[i] < 0) swap(imax, imin);
            imax = max(nums[i], imax*nums[i]);
            imin = min(nums[i], imin*nums[i]);
            res = max(res, imax);
        }

        return res;
    }
};