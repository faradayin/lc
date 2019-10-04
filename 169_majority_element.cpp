/**
 * Given an array of size n, find the majority element. 
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
*/
//最简单的方法，Boyer-Moore Majority Vote Algorithm
//不同的数相互抵消，最后剩下的一定是出现次数最多的数
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int major;
        int cnt = 0;
        for(auto n: nums)
        {
            if(cnt == 0)
            {
                cnt = 1;
                major = n;

            }
            else if(major == n) cnt++;
            else cnt--;
        }
        return major;
        
    }
};