/*
*  Author:      Sker <ksong666@163.com>
*  Descripton: 搜索
*state={" "}
*for	每个数字
*	for c=当前数字的所有备选字母
*		for s=state中的所有字符串
*			s+=c
*			将s加入到新的集合中去
*/
class Solution {
public:
    string chars[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        vector<string> state(1,"");
        for(auto u:digits)
        {
            vector<string> now;
            for(auto c:chars[u-'2'])
            {
                for(auto s:state)
                    now.push_back(s+c);
            }
            state=now;   
        }
        return state;
    }
};
