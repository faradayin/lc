class Solution {
public:
    string frequencySort(string s) 
    {
        vector<shared_ptr<vector<char>>> butt(s.size()+1, nullptr);
        unordered_map<char, int> m;
        for(auto c:s) m[c]++;
        for(auto p:m)
        {
            if(p.second != 0)
            {
                if(butt[p.second] == nullptr)  butt[p.second] = make_shared<vector<char>>();
                butt[p.second]->push_back(p.first);

                
            }
        }
        string res; 
        int j = butt.size()-1;
        while(j>0)
        {
            if(butt[j] != nullptr)
            {
                int jj = 0;
                while(jj < butt[j]->size())
                {
                    for(int cnt = 0; cnt<j; cnt++) res.push_back((*(butt[j]))[jj]);
                    jj++;
                }

            }
            j--;
        }
        return res;
        // I think there is a easy scheme
        // no, there's not.
        
    }

};