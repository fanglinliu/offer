/**
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/


class Solution {
public:
    vector<string> Permutation(string str) {
        sort(str.begin(), str.end());
        int count = str.size();
        for (int i = str.size() - 1; i >= 1 ; i--) {
            count *= i;
        }
        
        vector<string> result;
        
        for (int i = 0; i < count; i++) {
            if (find(result.begin(), result.end(), str) == result.end()) {
                result.push_back(str);
            }
            next_permutation(str.begin(), str.end());
        }
        
        return result;
    }
};