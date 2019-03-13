/**
机器人的运动范围

题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，
它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/




class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int size = rows * cols;
        bool *array = new bool[rows * cols];
        fill(array, array + size, false);
        matrix = (bool **)array;
        this->rows = rows;
        this->cols = rows;

        return _movingCount(threshold, 0, 0);
    }
    
    int _movingCount(int threshold, int x, int y) {
        if ( greaterThanThreshold(threshold, x, y)) {
            return 0;
        }
        
        if (x < 0 || x >= rows || y < 0 || y >= cols) {
            return 0;
        }
        
       // int count = matrix[y][x] ? 0 : 1;
        int count = 1;
        return count + _movingCount(threshold, x - 1, y) + 
        _movingCount(threshold, x, y - 1) +
        _movingCount(threshold, x + 1, y) +
        _movingCount(threshold, x, y + 1);
    }
    
    bool greaterThanThreshold(int x, int y, int threshhod) {
        return sumOfNumbers(x) + sumOfNumbers(y) > threshhod;
    }
    
    int sumOfNumbers(int x) {
        int sum = 0;
        for (int xc = x; xc > 0;) {
            sum += xc%10;
            xc = xc / 10;
        }
        
        return sum;
    }
    
private:
    int cols, rows;
    bool **matrix;    
};