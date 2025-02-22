#include "arrays.hpp"
#include "prime_numbers.hpp"

#include <memory>
#include <stdio.h>

int main() {
    int num = 143747;
    if (is_prime(num)) {
        printf("%d is prime\n", num);
    } else {
        printf("%d is not prime\n", num);
    }

    int arr[] = {1, 2, 3, 3, 10};
    print_array(arr, sizeof(arr) / sizeof(int));
    int brr[] = {1, 4, 3, -4, 10, -58, 5, 8, 8, 78, -541, 9, -9, 7, -6, -5, -4, 1, 1, 50, 55, 55};
    insertion_sort(brr, sizeof(brr) / sizeof(int));
    print_array(brr, sizeof(brr) / sizeof(int));
    num    = 7;
    long i = binary_search(brr, sizeof(brr) / sizeof(int), num);
    printf("%d is at %ld\n", num, i);

    printf("sqrt(0) = %f \n", sqrt(0));
    printf("sqrt(1) = %f \n", sqrt(1));
    printf("sqrt(2) = %f \n", sqrt(2));
    printf("sqrt(0.5) = %f \n", sqrt(0.5));
    printf("sqrt(87) = %f \n", sqrt(87));

    int n = 1;

    switch (n) {
    case 1: {
        printf("n is %d. no breaking fall through\n", n);
    }
    case 2: {
        printf("n is %d. no breaking fall through\n", n);
        break;
    }
    default: {
        printf("n is %d. no breaking fall through\n", n);
    }
    }

    printf("n = %d\n", n);
    printf("please enter a numer\n");
    scanf("%d", std::addressof(n));
    printf("n = %d\n", n);
}