/**解题思路：模拟乘法手算
 * 要注意：
 * (1)对cal数组下标的控制[k-i-j]
 * (2)去除 leading zeros
 * 
 * 主要参考 http://www.cnblogs.com/TenosDoIt/p/3735309.html
*/

string multiply(string num1, string num2)
{
    int k = num1.size()+num2.size()-2;
    vector<int> cal(num1.size()+num2.size(), 0);
    for(int i=0; i<num1.size(); i++)
        for(int j=0; j<num2.size(); j++)
            cal[k-i-j] += (num1[i]-'0')*(num2[j]-'0');//you should notice that here is "+="
    int c = 0;
    for(int i=0; i<cal.size(); i++)
    {
            cal[i] += c;
            c = cal[i]/10;
            cal[i] = cal[i]%10;
    }
    //remove leading zeros
    int i = cal.size()-1;
    while(cal[i] == 0) i--;
    // result is 0
    if(i<0) return "0";

    //build final result
    string res;
    for(; i>=0; i--)
    {
        res.push_back('0'+cal[i]);
    }
    return res;
}