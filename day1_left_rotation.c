#include <stdio.h>
#include <stdlib.h>

int* rotateLeft(int d, int arr_count, int* arr, int* result_count) {
    
    *result_count = arr_count;
    int* result = (int*)malloc(arr_count * sizeof(int));

    d = d % arr_count;

    int index = 0;

    for (int i = d; i < arr_count; i++) {
        result[index++] = arr[i];
    }

    for (int i = 0; i < d; i++) {
        result[index++] = arr[i];
    }

    return result;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result_count;
    int* result = rotateLeft(d, n, arr, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d", result[i]);
        if (i != result_count - 1) {
            printf(" ");  // no extra space at end
        }
    }

    free(arr);
    free(result);

    return 0;
}