#include <iostream>
#include <cstdlib>
using namespace std;

long long gcd(long long n, long long m) {
    while(m != 0) {
        long long temp = m;
        m = n % m;
        n = temp;
    }
    return n;
}

long long lcm(long long n, long long m) {
    if(n == 0 || m == 0) return 0;
    return abs(n / gcd(n, m)) * m;
}

int main() {
    long long n = 123456 , m = 789012;
    cout << lcm(n , m) << endl;

    return 0;
}
