#include <iostream>
#include <vector>
class LongNum {
private:
    const int base = 1e9;
    std::vector<int> lnum;
    std::string printNum() {
        std::string ans = "";
        for(size_t i = lnum.size(); i > 0; --i) {
            ans += std::to_string(lnum[i - 1]);
        }
        return ans;
    }
public:
    LongNum(std::string s) {
        for(size_t i = s.size(); i > 0; i -= 9) {
            if(i < 9) {
                lnum.push_back(std::stoi(s.substr(0, i).c_str()));
                break;
            }
            else {
                lnum.push_back(std::stoi(s.substr(i - 9, 9).c_str()));
            }
        }
    }
    std::string print() {
        return printNum();
    }
    LongNum operator+(const LongNum& other)const {
        LongNum sum("0");
        sum.lnum.resize(std::max(lnum.size(),other.lnum.size()),0);
        int carry = 0;
        for (size_t i = 0; i < sum.lnum.size(); ++i) {
            int a = (i < lnum.size()) 
                ? lnum[i] 
                : 0;
            int b = (i < other.lnum.size()) 
                ? other.lnum[i] 
                : 0;
            sum.lnum[i] = a + b + carry;
            carry = sum.lnum[i] / base;
            sum.lnum[i] %= base;
        }
        if (carry > 0) {
            sum.lnum.push_back(carry);
        }
        return sum;
    }
    LongNum operator*(const LongNum& other) const {
        LongNum multiplication("0");
        multiplication.lnum.resize(lnum.size() + other.lnum.size());
        for (size_t i = 0; i < lnum.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.lnum.size(); ++j) {
                long long tmp = static_cast<long long>(lnum[i]) * other.lnum[j] + multiplication.lnum[i + j] + carry;
                multiplication.lnum[i + j] = tmp % base;
                carry = tmp / base;
            }
            multiplication.lnum[i + other.lnum.size()] = carry;
        }
        while (multiplication.lnum.size() > 1 && multiplication.lnum.back() == 0) {
            multiplication.lnum.pop_back();
        }
        return multiplication;
    }
};

 