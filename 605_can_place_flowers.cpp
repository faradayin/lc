class Solution {
public:
    bool canPlaceFlowers(vector<int>& fbed, int n) {
        int cnt = 0;
        bool bb = true;
        for(int i=0; i<fbed.size(); i++ )
        {
            if(fbed[i] == 0)
            {
                if(bb && ((i!=fbed.size()-1 && fbed[i+1]==0)||(i==fbed.size()-1)))
                {
                    cnt ++;
                    bb = false;
                    continue;
                }
                bb = true;
            }
            else//fbed[i] == 1
            {
                bb = false;
            }
        }
        return cnt >= n;
    }
};