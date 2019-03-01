/**
第一个只出现一次的字符

题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int counts[256] = {0};
        for_each(str.begin(), str.end(), [&](char c){
            counts[c]++;
        });
        
        auto it = find_if(str.begin(), str.end(), [&](char c) {
            return counts[c] == 1;
        });
        
        if (it == str.end()) {
            return -1;
        } else {
            return it - str.begin();
        }
    }
};