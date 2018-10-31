/**解体思路：
 * 本题不涉及高级算法，无非是遍历
 * 把所有字符串第i个字符是否相同，实现为一个子函数same()；然后从下标0开始，调用same()即可
 * 应该注意的问题：
 * 1）首先应该确定所有字符串的最小长度len，避免数组超范围；
 * 2）要考虑到字符串可能是空
 * 3）要考虑到strs可能为空，带来的下标访问问题

*/


class Solution {
private:
bool same(vector<string>& strs, int i)
{
    for(int s=0; s<strs.size(); s++)
    {
        if(strs[s][i] != strs[0][i])
            return false;
    }
    return true;
}
public:
string longestCommonPrefix(vector<string>& strs)
{   
    string com;
    if(strs.size()==0)
        return com;
    
    int len = strs[0].size();
    for(auto &s: strs)
        len = s.size()<len? s.size() : len;
    int i = 0;
    while(i<len)
        if(same(strs, i))
            {
                com.push_back(strs[0][i]);
                i++;
            }
        else
            break;
    return com;

}
};