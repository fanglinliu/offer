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
        
        priority_queue<int> queue;
        for (int i = 0; i < input.size(); ++i)
        {
        	if (i < k)
        	{
	        	queue.push(input[i]);
        	} else {
        		if (input[i] < queue.top())
        		{
        			queue.pop();
        			queue.push(input[i]);
        		}
        	}
        }
        return vector<int>(queue.begin(), queue.end());
    }
};