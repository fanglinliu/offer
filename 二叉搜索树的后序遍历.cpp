/**题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return VerifySquenceOfBST(sequence.begin(), sequence.end());
    }
    
    bool VerifySquenceOfBST(vector<int>::iterator start, vector<int>::iterator end) {
        if (end - start == 0) {
            return false;
        }
        
        if (end - start <= 2) {
            return true;
        }
        
        int rootValue = *(end - 1);
        auto it = find_if(start, end, [rootValue](auto val) {
            return val > rootValue;
        });
        
        if (it == end ) {
            return VerifySquenceOfBST(start, end - 1);
        }
        
        if (!all_of(it, end - 1, [rootValue](auto val) { return val >= rootValue; })) {
            return false;
        }
        
        if (it - start > 0 && !VerifySquenceOfBST(start, it)) {
            return false;
        }
            
        if (end - 1 - it > 0 && !VerifySquenceOfBST(it, end - 1)) {
            return false;
        }
        
        return true;
    }
};