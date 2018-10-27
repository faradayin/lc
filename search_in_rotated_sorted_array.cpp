int search(vector<int>& n, int target)
{
    int l = 0, r = n.size()-1;
    while(l < r)
    {//二分搜索rotate点
        int m = (l+r)/2;
        if(n[m]>n[r]) 
            l = m+1;
        else
            r = m; 
    }
    //此时 l == r，为最小点

    int rot = l;
    //二分搜索target
    l = 0; r = n.size()-1;
    while(l <= r)
    {//这里搜索时，更新m的方法，我实在不太理解
        int m = (l+r)/2;
        int real_m = (m+rot)%n.size();
        if(n[real_m] == target) return real_m;
        if(n[real_m] < target) l = m+1;
        else r = m-1;
    }
    return -1;
}


//另一个解法
int search(vector<int>& n, int target)
{
    int l = 0, r = n.size()-1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(n[m] == target) return m;
        if(n[l] <= n[m])
        {
            if(target >= n[l] && target < n[m]) r = m-1;
            else l = m+1;


        }
        else
        {
            if(target > n[m] && target <= n[r]) l = m+1;
            else r = m-1;
        }
    }
    return -1;
}