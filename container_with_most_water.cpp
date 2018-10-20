#include <vector>
#include <iostream>
using namespace std;
/**解题思路：夹逼法
 * 1）从左右两端开始，总是移动高度较低的指针，因为较低的边总是限制容器的容积，如果移动高度较高的指针，容器容积不可能增大；
 * 2）移动高度较低的指针，*不一定*能使得容积增加，仍然需要遍历
 * 仍然还有一个疑虑是：两端高度相等的时候，该动哪一边呢？好像无论动哪边都能通过judge，不太理解了！！！

*/
int area(size_t i, size_t j, vector<int>& a)
{
    return (j-i)*(a[i]<a[j]? a[i]: a[j]);
}

int maxArea(vector<int>& height)
{
    size_t i = 0, j = height.size()-1;
    int s = area(i, j, height);
    while(i<j)
    {
        s = s>= area(i, j, height)? s: area(i, j, height);
        if(height[i]<height[j]) i++;
        else j--;
    }
    return s;
}


/***本人一开始错误的解法**
size_t area(size_t i, size_t j, vector<int>& a)
{
    return (j-i)*(a[i-1]<a[j-1]? a[i-1]: a[j-1]);
}
vector<size_t> maxArea(vector<int>& height)
{
    size_t i = 1, j = 2;
    size_t is = i, js = j;
    size_t s = area(is, js, height);
    while(j <= height.size())
    {
        if(area(i, j, height) >= s)
        {
            js = j;
            s = area(is, js, height);

        }
        j++;

    }
    while(i<js)
    {
        if(height[i-1]> height[is-1])
            if(area(i, js, height)> s)
            {
                is = i;
                s = area(is, js, height);
            }
        i++;

    }
    
    return vector<size_t>({s, is, js});

}


int main()
{
    //vector<int> a = {1,8,6,2,5,4,8,3,7};
    vector<int> a = {2,3,4,5,18,17,6};
    auto res = maxArea(a);
    for(auto &i: res)
        cout<< i<< "\t";
    cout<< endl;
    return 0;
}
*/