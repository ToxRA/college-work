#include <stdio.h>
#include <math.h>

long long int karatsuba(long long int x, long long int y) {
    // Base case for recursion
    if (x < 10 || y < 10)
        return x * y;

    // Calculate the size of the numbers
    int n = (int)fmax(log10(x) + 1, log10(y) + 1);
    int m = n / 2;

    // Split the digit sequences about the middle
    long long int high1 = x / (long long int)pow(10, m);
    long long int low1 = x % (long long int)pow(10, m);
    long long int high2 = y / (long long int)pow(10, m);
    long long int low2 = y % (long long int)pow(10, m);

    // 3 calls made to numbers approximately half the size
    long long int z0 = karatsuba(low1, low2);
    long long int z1 = karatsuba((low1 + high1), (low2 + high2));
    long long int z2 = karatsuba(high1, high2);

    return z2 * (long long int)pow(10, 2 * m) + (z1 - z2 - z0) * (long long int)pow(10, m) + z0;
}

int main() {
    long long int num1, num2;

    printf("---MULTIPLYING LONG INTEGERS USING KARATSUBA---\n");

    printf("Enter first number: ");
    scanf("%lld", &num1);

    printf("Enter second number: ");
    scanf("%lld", &num2);

    long long int result = karatsuba(num1, num2);

    printf("Result: %lld\n", result);

    return 0;
}
