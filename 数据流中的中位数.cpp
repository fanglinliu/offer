/**
数据流中的中位数

题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。


*/


class Solution {
public:
    void Insert(int num)
    {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double GetMedian()
    {
        if (maxHeap.size() == minHeap.size()) {
            return ((double)maxHeap.top() + minHeap.top())/2;
        } else {
            return maxHeap.top();
        }
    }
    
    
 private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};