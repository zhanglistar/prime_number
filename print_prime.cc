#include <stdlib.h>
#include <iostream>
#include <limits.h>

using namespace std;

#define TRUE 1
#define FALSE 0

void primeNumbersBySieveOfEratosthenes (size_t n) {

    // 初始化素数数组
    char* num = (char*) malloc(sizeof(char) * n );
    for ( size_t i = 2; i < n; ++i ) {       
        num[i] = TRUE;                       
    }
    // 按照埃拉托斯特尼筛法，将为基数的倍数的所有数标记为非素数。
    size_t i = 2;
    while ( i * i  <= n ) {
        for (size_t c = 2, idx = 2*i; idx < n; ++c, idx = i * c) {
            num[idx] = FALSE;
        }
        do {
            ++i;
        } while ( i * i <= n && num[i] == FALSE);
    }
    for (int i = 2; i < n; ++i) {
        if (num[i]) {
            cout << i << ",";
        }
    }
    free(num);
}

int main() {
    primeNumbersBySieveOfEratosthenes(INT_MAX);
    return 0;
}

