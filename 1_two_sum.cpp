
//两次遍历哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        for(int i = 0;i<nums.size();i++)
            m[nums[i]] = i;
        for(int i = 0;i<nums.size();i++)
        {
            int c = target-nums[i];
            if(m.count(c)&&m[c]!=i)
                return vector<int>{i,m[c]};

        }    
        
            
    }
};

//一次遍历哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        for(int i = 0;i<nums.size();i++)
        {
            if (m.count(target - nums[i])) 
            {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;//如果哈希表中没找到另一个，另一个会找到该项
        }
        return {};
    }
        
            
};