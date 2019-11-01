class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0) return res;
        res.push_back(intervals[0]);
        if(intervals.size() <= 1) return res;
        int j = 0;
        for(int i=1; i<intervals.size(); i++)
        {
            int lj = res[j][0];
            int rj = res[j][1];
            int li = intervals[i][0];
            int ri = intervals[i][1];

            if(li >= lj && li <= rj)
            {   
                res[j][1] = rj > ri? rj:ri;

            }
            else if(li <= lj && ri >= lj)
            {
                res[j][0] = li;
                res[j][1] = rj > ri? rj:ri;
            }
            else 
            {
                res.push_back(intervals[i]);
                j++;
            }
        }
        return res;
        
    }
};