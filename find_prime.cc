#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

bool is_prime(int n) {
    //cout << n << endl;
    int upper = sqrt(n);
    for (int i = 2; i <= upper; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int find_prime(int n) {
    while (n < INT_MAX) {
        if (is_prime(n)) {
            return n;
        }
        ++n;
    }
    return INT_MAX;
}

int main() {
    int n;
    n = 2000000000;
        cout << n << endl;
        cout << find_prime(n) << endl;
    return 0;
}
