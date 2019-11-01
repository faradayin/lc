/**解题思路：
 * 很简单的一道题，却花去一上午的时间。遇到的问题包括以下几点：
 * 1）有时候要append字符char，有时候需要append字符串string，这里我用了两个map
 * 2）琐碎的边界问题，限制不严格，容易出现意想不到的结果；
 * 
 * Discuss里有非常精妙的方法，就是查表从1~9，统统查表
 * 

*/

string intToRoman(int num) 
{
    unordered_map<int, char> m{{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'},{100, 'C'}, {500, 'D'}, {1000, 'M'}};
    unordered_map<int, string> ms{{900, "CM"}, {400, "CD"}, {40, "XL"}, {90, "XC"}, {4, "IV"}, {9, "IX"}};
    string res;
    //1000
    int s = num/1000;
    num = num%1000;
    res.append(s,m[1000]);
    
    //100-1000
    s = num/100;
    num = num%100;
    if(s == 9)
        res.append(ms[900]);
    else if(s == 4)
        res.append(ms[400]);
    else if(s > 0 &&s < 4)
        res.append(s, m[100]);
    else if(s >= 5 && s < 9)
    {
        res.push_back(m[500]);
        res.append(s-5, m[100]);
    } 
    //10-100  
    s = num/10;
    num = num%10;
    if(s == 9)
        res.append(ms[90]);
    else if(s == 4)
        res.append(ms[40]);
    else if(s > 0 && s < 4)
        res.append(s, m[10]);
    else if(s >= 5 && s < 9)
    {
        res.push_back(m[50]);
        res.append(s-5, m[10]);
    }
    //1-10
    s = num;
    if(s == 9)
        res.append(ms[9]);
    else if(s == 4)
        res.append(ms[4]);
    else if(s > 0 && s < 4)
        res.append(s, m[1]);
    else if(s >= 5 && s < 9 )
    {
        res.push_back(m[5]);
        res.append(s-5, m[1]);
    }
    return res;

}