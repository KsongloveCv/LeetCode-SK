/*
*  Author:      Sker <ksong666@163.com>
*  File:        tle_bruteforce_n2.cpp
*  Descripton:  暴力枚举O(n2)  由于字符串长度小于1000，因此我们可以用 O(n2) 的算法枚举所有可能的情况。
* 首先枚举回文串的中心 i，然后分两种情况向两边扩展边界，直到遇到不同字符为止:
* 回文串长度是奇数，则依次判断 s[i−k]==s[i+k],k=1,2,3,…
* 回文串长度是偶数，则依次判断 s[i−k]==s[i+k−1],k=1,2,3,…
* 如果遇到不同字符，则我们就找到了以 i
* 为中心的回文串边界。
* 时间复杂度分析：一共两重循环，所以时间复杂度是 O(n2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i=0;i<s.size();i++)
        {
            int j,k; //j往左，k往右
            for(int j=i,k=i;j>=0&&k<s.size()&&s[j]==s[k];j--,k++)
            {
                if(res.size()<k-j+1)
                {
                    //获得字符串s中从第0位开始的长度为5的字符串
                    res=s.substr(j,k-j+1);
                }
            }
            for(int j=i,k=i+1;j>=0&&k<s.size()&&s[j]==s[k];j--,k++)
            {
                if(res.size()<k-j+1)
                {
                    res=s.substr(j,k-j+1);
                }
            }
        }
        return res;   
    }
};
