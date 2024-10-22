#include <iostream>
#include <vector>
using namespace std;
bool CheckBound(int x, int y, int n) {
    return x < n && y >= 0;
}
bool SearchInMatrix1(const vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int idx = 0;
    int idy = m - 1;
    while(idx < n && idy >= 0) {
        while(CheckBound(idx, idy, n) && matrix[idx][idy] < target) {
            ++idx;
        }
        while(CheckBound(idx, idy, n) && matrix[idx][idy] > target) {
            --idy;
        }
        if(CheckBound(idx, idy, n) && matrix[idx][idy] == target) {
            return true;
        }
    }
    return false;
}
int main() {
    vector<vector<int>> matrix = {
        {{15, 20, 40, 85}, 
        {20, 35, 80, 95}, 
        {30, 55, 95, 105}, 
        {40, 80, 100, 120}}
    };
    int target = 95;
    cout << SearchInMatrix1(matrix, target);
    return 0;
}
