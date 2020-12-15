#include<iostream>
using namespace std;

// a^-1 mod m
long long minv(long long a, long long m) {
    if (a == 1) return 1;
    return m - minv(m % a, a) * m / a;
}

// equivalent to the above minv and can be simplified to it, but more intuitive
long long minva(long long a, long long m) {
    if (a == 1) return 1;
    int prev = minva(m % a, a);
    return m -((m % a) * prev - 1) / a - prev * (m / a);
}

int main() {
    std::cout << minv(3333, 2017);

}