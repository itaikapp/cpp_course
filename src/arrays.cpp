#include "arrays.hpp"

#include <stdio.h>

void print_array(int *arr, size_t size) {
    printf("{");
    for (size_t i = 0; i + 1 < size; ++i) {
        printf("%d, ", arr[i]);
    }
    if (size > 0) {
        printf("%d", arr[size - 1]);
    }
    printf("}\n");
}

static size_t find_min(int *arr, size_t lo, size_t hi) {
    int    min     = arr[lo];
    size_t min_idx = lo;
    for (size_t i = lo + 1; i <= hi; ++i) {
        if (arr[i] < min) {
            min     = arr[i];
            min_idx = i;
        }
    }
    return min_idx;
}

static void swap(int *arr, size_t i, size_t j) {
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
}

void selection_sort(int *arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        size_t min_idx = find_min(arr, i, size - 1);
        swap(arr, i, min_idx);
    }
}

void insertion_sort(int *arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        int    num = arr[i];
        size_t j   = i - 1;
        while (j + 1 != 0 && num < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[1 + j] = num;
    }
}

long search(int *arr, long size, int num) {
    for (long i = 0; i < size; ++i) {
        if (num == arr[i]) {
            return i;
        }
    }
    return -1;
}

static long binary_search(int *arr, long lo, long hi, int num) {
    if (lo >= hi) {
        return -1;
    }
    long mid = (lo + hi) / 2;
    if (arr[mid] == num) {
        return mid;
    } else if (arr[mid] > num) {
        return binary_search(arr, lo, mid, num);
    } else {
        return binary_search(arr, mid + 1, hi, num);
    }
}

long binary_search(int *arr, long size, int num) { return binary_search(arr, 0, size, num); }

static const float eps = 0.00001;

static float abs(float num) {
    if (num >= 0) {
        return num;
    }
    return -num;
}

static float sqrt(float num, float lo, float hi) {
    float mid = (lo + hi) / 2;
    float sqr = mid * mid;
    if (abs(num - sqr) < eps) {
        return mid;
    }
    if (sqr > num) {
        return sqrt(num, lo, mid);
    }
    return sqrt(num, mid, hi);
}

float sqrt(float num) {
    if (num > 1) {
        return sqrt(num, 1, num);
    }
    return sqrt(num, 0, 1);
}
// void insertion_sort(int *arr, size_t size);
// void quick_sort(int *arr, size_t size);
