class Solution {
public:
//DP,把局部最优解存在缓存数组里
    int rob(vector<int>& n) 
    {
        if(n.size() == 0) return 0;
        if(n.size() == 1) return n[0];
        vector<int> temps(n.size(), 0);
        temps[0] = n[0];
        temps[1] = max(n[0], n[1]);
        for(int i=2; i < n.size(); i++)
        {
            temps[i] = max(temps[i-2] + n[i], temps[i-1]);
        }
        return temps[n.size()-1];
    }



    
};