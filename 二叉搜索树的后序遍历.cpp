/**题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return false;
        }
        
        return VerifySquenceOfBST(sequence.begin(), sequence.end());
    }
    
    bool VerifySquenceOfBST(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin == end) {
            return true;
        }
        
        --end;
        
        auto it = find_if(begin, end, [=](auto value) {
            return value > *end ;
        });
        
        return all_of(it, end, [=](auto value) { return value > *end; }) && 
            VerifySquenceOfBST(begin, it) &&
            VerifySquenceOfBST(it, end);
    }
    
};