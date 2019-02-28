/**整数中1出现的次数
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）
*/

#include <cassert>

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for (int divider = 1; n / divider > 0; divider *= 10) {
            cnt++;
            int i = n / (divider * 10);
            int j = (n % (divider * 10)) / divider;
            int k = n % divider;
            count += (i + (j > 1)) * divider + (j == 1) * (k + 1);
        }
        
        return count;
    }
};