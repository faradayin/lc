int lengthOfLongestSubstring(string s) 
{
    vector<int> m(255,-1);//存放字符地址标号
    int maxL = 0;
    int start = -1;
    for(int i=0; i<s.length();)
    {
        if(m[s[i]] > start)//该字符在当前窗口中出现重复，下面要调整窗口左侧边界至重复的字符
            start = m[s[i]];
        m[s[i]] = i;//记录当前字幕的地址标号
        maxL = maxL > (i-start)? maxL: (i-start);
        i++;//窗口右侧边界递增
    }
    return maxL;
}
/***解决思路：
滑动窗口，左侧边界start,初始值为-1；右侧边界i，随着迭代递增i++
关键点在于左侧边界的更新：
出现重复的判定条件是当前检查的字符s[i]上一次出现的下标，如果该下标m[s[i]]>start，说明该字符在当前滑动窗口中第二次出现，此时调整左侧边界至第一次出现处 ；
至于为何可以将左边界调整到字符第一次出现处，而非递增？因为既然现在该字符重复了，如果采用递增左边界，该窗口中必定仍然重复（除非重复的是窗口中第一个字符）；
所以索性直接跳过该字符第一次出现的位置，将start置为m[s[i]]；
m[s[i]]中存储的值永远是当前字符上一次出现的位置；
每次调整窗口边界后，都要更新maxL
*/