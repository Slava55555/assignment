#include <iostream>
#include <vector>
#include <stack>
//task4
std::vector<int>FindDayDefectiveDetails(std::vector<int>& nums) {
    int len = nums.size();
    std::stack<int>st;
    std::vector<int>answer(len,0);
    for(size_t i = 0; i < len; ++i) {
        while(!st.empty() && nums[st.top()] < nums[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return answer;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> num(n);
    for(size_t i = 0; i < n; ++i) {
        std::cin >> num[i];
    }
    for(auto el:FindDayDefectiveDetails(num)) {
        std::cout << el << " ";
    }
}