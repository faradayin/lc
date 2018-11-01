/**我写的垃圾代码
 * 
*/
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> res;
    int nr = matrix.size(), nc = matrix[0].size();
    for(int i=0; i < min(nr, nc)/2; i++)
    {
        //第i圈
        for(int j = i; j < nc-i; ++j)
            res.push_back(matrix[i][j]);
        for(int j = i+1; j < nr-i; ++j)
            res.push_back(matrix[j][nc-i-1]);
        for(int j = nc-i-2; j >= i; --j)
            res.push_back(matrix[nr-i-1][j]);
        for(int j = nr-i-2; j > i; --j)
            res.push_back(matrix[j][i]);

    }
}