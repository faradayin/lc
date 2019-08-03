class Solution {
public:
// 贪心思想，每次向后遍历时，尽量留出更大空间，以使后面的区间不容易交叠
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        auto comp = [](const vector<int>& i1, const vector<int>&i2){return i1[1] < i2[1];};
        // 用lambda表达式初始化可调用对象comp
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0, pre = 0;
        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i][0] < intervals[pre][1])// 出现交叠
            {
                res ++;
                if(intervals[i][1] < intervals[pre][1]) // 当前区间被前面区间包括
                    pre = i;// 贪心的策略，移除更大的区间
            }
            else pre = i;
        }
        return res;
        
    }
};