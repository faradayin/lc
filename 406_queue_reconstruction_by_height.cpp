#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    void print_vec(vector<vector<int>> t)
    {
        for(auto &p:t)
        {
            cout<<p[0]<<","<<p[1]<<"\t";
        }
        cout<<endl;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //sort with height descending
        //sort with k ascending
        auto cmp = [](const vector<int> &p1, const vector<int> &p2){return p1[0]>p2[0] || (p1[0]==p2[0] && p1[1]<p2[1]);};
        // auto cmp = [](const vector<int> &p1, const vector<int> &p2){return p1[0] == p2[0]? p1[1] < p1[1] : p1[0] > p2[0];};//排出来不对
        sort(people.begin(), people.end(), cmp);
        print_vec(people);
        vector<vector<int>> res;
        for(auto p : people)
        {
            res.insert(res.begin()+p[1], p);
            cout<<p[0]<<","<<p[1]<<":\t";
            print_vec(res);
        }
        return res;
    }

int main()
{
    vector<vector<int>> test = {{8,2},{4,2},{4,5},{2,0},{7,2},{1,4},{9,1},{3,1},{9,0},{1,0}};
    print_vec(test);
    auto res = reconstructQueue(test);
    print_vec(res);

}