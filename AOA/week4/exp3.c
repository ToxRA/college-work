#include <stdio.h>
#include <math.h>

int len;

// Karatsuba Algo
long long int multiplyLong(long long int a, long long int b, long long int c, long long int d) {
    long long int s1 = a * c;
    long long int s2 = b * d;
    long long int s3 = (a + b) * (c + d);
    long long int s4 = s3 - s2 - s1;
    
    long long int result = s1*( pow(10, len) ) + s4*( pow(10, len / 2) ) + s2;

    return result;
}

int main () {
    int mid = len / 2;
    long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

    long long int a[len];
    long long int b[len];

    printf("---MULTIPLYING LONG INTEGERS---\n");
    printf("Enter the length of digits: ");
    scanf("%d", &len);

    printf("Enter the first number: ");
    for (int i = 0; i < len; i++) {
        scanf("%lld", &a[i]);
    }

    printf("Enter the second number: ");
    for (int i = 0; i < len; i++) {
        scanf("%lld", &b[i]);
    }
    
    for(int i = 0; i < mid; i++) {
        a1 = a1*10 + a[i];
        b1 = b1*10 + b[i];

        a2 = a2*10 + a[mid+i];
        b2 = b2*10 + b[mid+i];
    }

    long long int result = multiplyLong(a1, a2, b1, b2);
    printf("%ld \n", result);

    return 0;
}