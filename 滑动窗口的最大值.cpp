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

/***

滑动窗口的最大值

*/

#include <cassert>

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if (size <= 0) {
            return {};
        }
        
        if (num.size() < size) {
            return {};
        }
        
        maxNumIndex.push_front(size - 1);
        for (int i = size - 2; i >= 0; i--) {
            if (num[i] > num[maxNumIndex.front()]) {
                maxNumIndex.push_front(i);
            }
        } 
        
        vector<int> result;
        result.push_back(num[maxNumIndex.front()]);
        
        for (int i = size; i < num.size(); i++) {
            int winBegin = i - size + 1;
            int winEnd = i;
            if (!maxNumIndex.empty() && maxNumIndex.front() < winBegin) {
                maxNumIndex.pop_front();
            }
            
            while (!maxNumIndex.empty() && num[maxNumIndex.back()] <= num[i]) {
                maxNumIndex.pop_back();
            }
            maxNumIndex.push_back(i);
            result.push_back(num[maxNumIndex.front()]);
        }
        
        
        return result;
    }
    
private:
    
    deque<int> maxNumIndex;
};