#include <iostream>

//ref1 https://arxiv.org/pdf/1012.0284.pdf
//ref2 https://stackoverflow.com/questions/32272794/finding-the-nth-fib-number-in-ologn
long long int fib(long long int n) {
    long long int a, b, p, q;
    a = q = 1;
    b = p = 0;
    while (n > 0) {
        if (n % 2 == 0) {
            long long int qq = q * q;
            q = 2 * p * q + qq;
            p = p * p + qq;
            n /= 2;
        }
        else {
            long long int aq = a * q;
            a = b * q + aq + a * p;
            b = b * p + aq;
            n -= 1;
        }

        a %= 1'000'000'007, b %= 1'000'000'007 , p %= 1'000'000'007 , q %= 1'000'000'007;

    }
    return b;
}

int main() {
	long long int N;

	std::cin >> N;
    
    std::cout << fib(N);
    return 0;
}