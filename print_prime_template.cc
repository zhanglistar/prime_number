#include <iostream>
#include <limits.h>

using namespace std;

template<int N, int D = N - 1>
struct isPrime {
    enum {
        result = (N % D) && isPrime<N, D-1>::result
    };
};
 
template<int N>
struct isPrime<N, 1> {
    enum {
        result = true
    };
};

template<int N, bool ISPRIME>
struct printIfPrime {
    static inline void print() {}
};
 
template <int N>
struct printIfPrime<N, true> {
    static inline void print() {
        cout << N << ",";
    }
};

template<int N, int MAX>
struct printPrimes {
    static inline void print()
    {
        printIfPrime<N, isPrime<N>::result>::print();
        printPrimes<N + 1, MAX>::print();
    }
};

template<int N>
struct printPrimes<N, N> {
    static inline void print() {
        printIfPrime<N, isPrime<N>::result>::print();
    }
};

int main (int argc, char * const argv[]) {
    //int max_int = std::numeric_limits<int>::max();
    printPrimes<2, INT_MAX>::print();
    cout << endl;
    return 0;
}
