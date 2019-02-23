/**
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/



class Solution {
public:
    vector<string> Permutation(string str) {        
        if (str.empty()) {
            return vector<string>();
        }
        
        sort(str.begin(), str.end());
        vector<string> result;
        result.push_back(str);
        while(next_permutation(str)) {
            result.push_back(str);
        }
        
        return result;
    }
    
    bool next_permutation(string &str) {
       // reverse(str.begin(), str.end());
        auto it = adjacent_find(str.rbegin(), str.rend(), [](auto c1, auto c2){
            return c1 > c2;
        });
        
        if (it == str.rend()) {
            return false;
        }
        
        it++;
        
        auto it2 = find_if(str.rbegin(), it, [=](auto c){
            return c > *it;
        });
        
        swap(*it2, *it);
        reverse(str.rbegin(), it);
        //reverse(str.begin(), str.end());
        
        return true;
    }
};

