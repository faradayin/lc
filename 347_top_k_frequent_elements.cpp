class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        for(auto &n: nums) m[n] +=1;
        vector<shared_ptr<vector<int>>> butt(nums.size()+1, nullptr);//butt是一个指针数组，butt[i]:指针，指向一个vector存储出现i次的数
        for(auto &p: m)
        {
            
            if(p.second != 0) 
            {
                if(butt[p.second] == nullptr) butt[p.second] = make_shared<vector<int>>();
                butt[p.second]->push_back(p.first);
            }

        }
        vector<int> res;
        int j = butt.size()-1;
        while(res.size() != k && j >= 0)
        {
            if(butt[j] != nullptr)
            {
                int jj = 0;
                while(res.size() != k && jj < butt[j]->size()) 
                {
                    res.push_back((*(butt[j]))[jj]);
                    jj++;
                }
            }
            j--;
        }
        return res;
    }
};
