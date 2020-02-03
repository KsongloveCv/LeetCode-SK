/*
*  Author:      Sker <ksong666@163.com>
*  Descripton:   定义两个指针 i,j(i<=j)，表示当前扫描到的子串是 [i,j] (闭区间)。扫描过程中维护一个哈希表unordered_map<char,int> hash，
*表示 [i,j]中每个字符出现的次数。线性扫描时，每次循环的流程如下：
*1. 指针j向后移一位, 同时将哈希表中 s[j]的计数加一:hash[s[j]]++。
*2.假设 j移动前的区间 [i,j] 中没有重复字符，则 j 移动后，只有 s[j] 可能出现2次。因此我们不断向后移动 i，直至区间 [i,j]中 s[j]的个数等于1为止。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j ++ )
        {
            hash[s[j]] ++ ;
            while (hash[s[j]] > 1) hash[s[i ++ ]] -- ;
            res = max(res, j - i + 1);
        }
        return res;
    }
};
