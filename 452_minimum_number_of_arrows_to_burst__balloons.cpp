class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        auto cmp = [](const vector<int>& i1, const vector<int>& i2){return i1[1]<i2[1];};// 按区间尾部坐标排序
        sort(points.begin(), points.end(),cmp);
        //向后遍历，尽量以一箭解决最多的气球
        int end = points[0][1];
        int cnt = 1;
        for(int i = 1; i<points.size(); i++)
        {
            if(points[i][0] <= end)
                continue;
            cnt++;
            end = points[i][1];
        }
        return cnt;
        
    }
};