class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> dist(n);
        stack<int> idx;
        for(int c = 0; c < n; c++)
        {
            while(!idx.empty() && T[c] > T[idx.top()])
            {
                int pre = idx.top();
                idx.pop();
                dist[pre] = c - pre;
            }
            idx.push(c);
        }
        return dist;
    }
};