#include <stdio.h>

long long int intPow(int base, int exp) {
    long long int result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

void multiplyLong(long long int a, long long int b, long long int c, long long int d, int len) {
    long long int s1 = a * c;
    long long int s2 = b * d;
    long long int s3 = (a + b) * (c + d);
    long long int s4 = s3 - s2 - s1;

    long long int result = s1 * intPow(10, len) + s4 * intPow(10, len / 2) + s2;
    printf("\nResult: %lld\n", result);
}

int main () {
    int len;
    printf("\nHello.. Welcome to Long Int Multiplier!\n");
    printf("Enter length of number (even digits): ");
    scanf("%d", &len);

    int a[20] = {}, b[20] = {};
    printf("\nEnter digits for number 1:\n");
    for(int j = 0; j < len; j++) {
        printf("Digit %d: ", j+1);
        scanf("%d", &a[j]);
    }

    printf("\nEnter digits for number 2:\n");
    for(int j = 0; j < len; j++) {
        printf("Digit %d: ", j+1);
        scanf("%d", &b[j]);
    }

    int mid = len / 2;
    long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

    for(int i = 0; i < mid; i++) {
        a1 = a1 * 10 + a[i];
        b1 = b1 * 10 + b[i];
        a2 = a2 * 10 + a[mid + i];
        b2 = b2 * 10 + b[mid + i];
    }

    multiplyLong(a1, a2, b1, b2, mid);
}