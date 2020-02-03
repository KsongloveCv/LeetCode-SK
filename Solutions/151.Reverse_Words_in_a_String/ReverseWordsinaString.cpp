/*
*  Author:      Sker <ksong666@163.com>
*  Descripton:  (数组翻转) O(n)
*分两步操作：
*将字符串中的每个单词逆序，样例输入变为: “eht yks si eulb”；
*将整个字符串逆序，样例输入变为：“blue is sky the”；
*时间复杂度分析：整个字符串总共扫描两遍，所以时间复杂度是 O(n)。且每次翻转一个字符串时，可以用两个指针分别从两端往中间扫描，每次交换两个指针对应的字符，所以额外空间的复杂度是 O(1)。
*/
class Solution {
public:
    string reverseWords(string s) {
        int k=0; //当前实际存的终点的位置
        for(int i=0;i<s.size();i++)
        {
            //先把连续空格过滤掉
            while(i<s.size()&&s[i]==' ') i++;
            if(i==s.size()) break;
            //否则
            int j=i;
            while(j<s.size()&&s[j]!=' ') j++;
            reverse(s.begin()+i,s.begin()+j);
            if(k) s[k++]=' ';
            while(i<j) s[k++]=s[i++];
        }
        s.erase(s.begin()+k,s.end());
        reverse(s.begin(),s.end());
        return s; 
    }
};
