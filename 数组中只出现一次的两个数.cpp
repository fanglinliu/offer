/** 
数组中只出现一次的两个数

题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。


*/


class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int count = 0;
        auto i = data.begin();
        auto j = data.begin() + data.size();
        
        while (j - i > 1 && count < sizeof(int) ) {
            auto mid = partition(i, j, [=](int val){
                return val & (1 << count);
            });
            count++;
            
            int firstSum = 0;
            int secondSum = 0;
            for_each(i, mid, [&](int val){
                firstSum ^= val;
            });

            for_each(mid, j, [&](int val){
                secondSum ^= val;
            });
            
            if (firstSum == 0) {
                i = mid;
            } else if (secondSum == 0) {
                j = mid;
            } else {
                *num1 = firstSum;
                *num2 = secondSum;
                return;
            }
        }
    }
};
