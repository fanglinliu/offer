/**最小的K个数
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() < k) {
            return vector<int>();
        }
        
        nth_element(input.begin(), input.begin() + k, input.end());
        return vector<int>(input.begin(), input.begin() + k);
    }
};