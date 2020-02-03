/*
*  Author:      Sker <ksong666@163.com>
*  Descripton:  按照「点」对版本号进行切割，然后依次比较每个数字即可。利用c++中的atoi函数将字符串变成数字进行比较。
*/
class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i=0,j=0;
        while(i<s1.size()||j<s2.size())
        {
            int x=i,y=j;
            while(x<s1.size()&&s1[x]!='.') x++;
            while(y<s2.size()&&s2[y]!='.') y++;
            int a=i==x?0:atoi(s1.substr(i,x-i).c_str());
            int b=j==y?0:atoi(s2.substr(j,y-j).c_str());
            if(a>b) return 1;
            if(a<b) return -1;
            i=x+1;
            j=y+1;
        }
        return 0;   
    }
};
