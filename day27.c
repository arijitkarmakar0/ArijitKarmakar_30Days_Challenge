#include <stdio.h>
#include <stdlib.h>

long arrayManipulation(int n, int queries_rows, int queries_columns, int queries[][3]) {

    long *arr = (long*)calloc(n + 2, sizeof(long));

    // Apply difference array logic
    for (int i = 0; i < queries_rows; i++) {

        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        arr[a] += k;

        if (b + 1 <= n) {
            arr[b + 1] -= k;
        }
    }

    long max = 0;
    long current = 0;

    // Prefix sum and find maximum
    for (int i = 1; i <= n; i++) {

        current += arr[i];

        if (current > max) {
            max = current;
        }
    }

    free(arr);

    return max;
}

int main() {

    int n, m;

    // Input array size and number of queries
    scanf("%d %d", &n, &m);

    int queries[m][3];

    // Input queries
    for (int i = 0; i < m; i++) {

        scanf("%d %d %d",
              &queries[i][0],
              &queries[i][1],
              &queries[i][2]);
    }

    long result = arrayManipulation(n, m, 3, queries);

    printf("%ld\n", result);

    return 0;
}