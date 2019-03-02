/**
数组中的逆序对

题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5

示例1
输入
复制
1,2,3,4,5,6,7,0
输出
复制
7
*/


class Solution {
public:
    int InversePairs(vector<int> data) {
        paritition_sort(data, 0, data.size());
        return count%1000000007;
    }
    
    void paritition_sort(vector<int> &data, int low, int high) {
        if (low >= high) {
            return;
        }
        
        int mid = partition(data, low, high);
        paritition_sort(data, low, mid - 1);
        paritition_sort(data, mid + 1, high);
    }
    
    int partition(vector<int> &data, int low, int high) {
        int pivot = data[high - 1];
        int secondStart = high;
        for (int i = low; i < high; i++) {
            if (data[i] > pivot) {
                secondStart = i;
                break;
            }
        }
        
        if (secondStart == high) {
            return high - 1;
        }
        
        for (int i = secondStart + 1; i < high - 1; i++) {
            if (data[i] < pivot) {
                swap(data[i], data[secondStart]);
                count += (i - secondStart) * 2 + 1;
                secondStart++;
            }
        }
        
        swap(data[secondStart], data[high - 1]);
        
        return secondStart;
    }
    
private:
    int count  = 0;
};
