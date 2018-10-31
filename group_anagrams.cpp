/**解题思路：
 * 把每个字符串所有的字符放在multiset里，用map记录每个multiset对应的字符串
*/
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<multiset<char>, vector<int>> ms;
    //   ^               ^
    //  字符集           对应的字符串索引
    vector<vector<string>> res;
    for(int i=0; i< strs.size(); i++)
    {
        multiset<char> tem(strs[i].begin(), strs[i].end());
        ms[tem].push_back(i);
    }
    for(auto &p: ms)
    {
        vector<string> tem;
        for(auto i: p.second)
            tem.push_back(strs[i]);
        res.push_back(tem);


    }
    return res;
}