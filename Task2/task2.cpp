#include "LongNum.h"
#include <iostream>
//task2
std::pair<LongNum, LongNum> SumAndMultiplication(LongNum& num1, LongNum& num2) {
    return {num1 + num2, num1 * num2};
}
int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    LongNum num1(s1);
    LongNum num2(s2);
    std::pair<LongNum, LongNum> answer = SumAndMultiplication(num1, num2);
    std::cout << answer.first.print() << '\n' << answer.second.print();
}