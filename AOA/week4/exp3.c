//Implement and Analyze time and space complexity of multiplying long Integers using divide and conquer strategy.

#include <stdio.h>
#include <math.h>

int a[4] = {1,2,3,4};
int b[4] = {5,6,7,8};
int len = 4;

// int expo(int base, int pow) {
//     int ans;
//     ans = 1;
//     for(int i = 0; i < pow; i++) {
//         ans *= base;
//     }

//     return ans;

// }

void multiplyLong(int a, int b, int c, int d) {
    int s1 = a*c;
    int s2 = b*d;
    int s3 = (a+b) * (c+d);
    int s4 = s3 - s2 - s1;
    
    long int result = s1*( (int)pow(10, len) ) + s4*( (int)pow(10, len / 2) ) + s2;

    printf("S1: %d\n", s1);
    printf("S2: %d\n", s2);
    printf("S3: %d\n", s3);
    printf("S4: %d\n", s4);

    printf("Result: %ld", result);
}

int main () {
    int mid = len/2;
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

    for(int i = 0; i < mid; i++) {
        a1 = a1*10 + a[i];
        b1 = b1*10 + b[i];

        a2 = a2*10 + a[mid+i];
        b2 = b2*10 + b[mid+i];
    }

    multiplyLong(a1, a2, b1, b2);
}