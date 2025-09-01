#include <iostream>
#include <cmath>
using namespace std;

long long countNumberOfDivisors(long long n) {
    if(n == 1) return 1; 
    long long count = 0;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            count += 2;
        }
    }

    long long sqrtN = sqrt(n);
    if(sqrtN * sqrtN == n) count--;

    return count;
}

int main() {
    long long num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Number of divisors: " << countNumberOfDivisors(num) << endl;

    return 0;
}
