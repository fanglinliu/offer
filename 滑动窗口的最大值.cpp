/** 滑动窗口的最大值

滑动窗口的最大值


题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

*/


#include <cassert>

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        if (num.size() < size) {
            return result;
        }
        
        if (size <= 0 || num.size() <= 0) {
            return result;
        }
        
        //assert(num.size() >= size);
        //assert(num.size() >= 0);
        //assert(size >= 0);
        
        //priority_queue<int> pq(num.begin(), num.begin() + size);
       
        priority_queue<int> pq;
        for (int i = 0; i < num.size(); i++) {
            pq.push(num[i]);
            if (i >= size) {
                result.push_back(pq.top());
                pq.pop();
            }
        }
        
        return result;
    }
};