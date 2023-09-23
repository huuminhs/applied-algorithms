#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

const unsigned long long divisor = 1000000000000000000;

int main() 
{ 
    unsigned long long a, b, c, tmp_a, tmp_b, tmp_sum;
    cin >> a;
    cin >> b;
    tmp_sum = a / divisor + b / divisor;
    c = a % divisor + b % divisor;
    if (c >= divisor) {
        tmp_sum++;
        c = c % divisor;
    }
    if (tmp_sum > 0) {
        cout << tmp_sum;
        cout << setw(18) << setfill('0') << c;
    } else {
        cout << c;
    }
    return 0;
}