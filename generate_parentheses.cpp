/**解题思路：递归!!
 * 应该注意的是递归函数如果减小问题规模，对于本题，
 * 可以放左括号的条件是：left < n 
 * 可以放右括号的条件是：left > right
 * 
*/

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    backtrack(res, "", 0, 0, n);
    return res;

}
void backtrack(vector<string> &r, string s, int left, int right, int n)
{
    if(s.size() == 2*n)
    {
        r.push_back(s);
        return;
    }
    if(left < n)//还可以放 (
        backtrack(r, s+"(", left+1, right, n);
    if(right < left)//还可以放 )
        backtrack(r, s+")", left, right+1, n);

}