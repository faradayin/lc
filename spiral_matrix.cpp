/**我写的垃圾代码
 * 错的
*/
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int nr = matrix.size(), nc = matrix[0].size();
    for (int i = 0; i < min(nr, nc) / 2; i++)
    {
        //第i圈
        for (int j = i; j < nc - i; ++j)
            res.push_back(matrix[i][j]);
        for (int j = i + 1; j < nr - i; ++j)
            res.push_back(matrix[j][nc - i - 1]);
        for (int j = nc - i - 2; j >= i; --j)
            res.push_back(matrix[nr - i - 1][j]);
        for (int j = nr - i - 2; j > i; --j)
            res.push_back(matrix[j][i]);
    }
}
// nice solution from discussion
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.empty())
        return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> spiral(m * n);
    int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
    while (true)
    {
        // up
        for (int col = l; col <= r; col++)
            spiral[k++] = matrix[u][col];
        if (++u > d)
            break;
        // right
        for (int row = u; row <= d; row++)
            spiral[k++] = matrix[row][r];
        if (--r < l)
            break;
        // down
        for (int col = r; col >= l; col--)
            spiral[k++] = matrix[d][col];
        if (--d < u)
            break;
        // left
        for (int row = d; row >= u; row--)
            spiral[k++] = matrix[row][l];
        if (++l > r)
            break;
    }
    return spiral;
}