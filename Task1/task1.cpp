#include <iostream>
//task1
bool IsOdd(int number) {
    return (number & 1) == 1;
}
int main() {
    int num;
    std::cin >> num;
    std::cout << IsOdd(num); 
}