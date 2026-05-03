#include <stdio.h>
#include <stdlib.h>

int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int sum = 0;
    int count = 0;

    int i = 0, j = 0;

    // Take elements from stack A
    while (i < a_count && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
    }

    count = i;

    // Take elements from stack B and adjust A if needed
    while (j < b_count) {
        sum += b[j];
        j++;

        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }

        if (sum > maxSum) {
            break;
        }

        if (i + j > count) {
            count = i + j;
        }
    }

    return count;
}

int main() {
    int g;
    scanf("%d", &g);

    while (g--) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        int* a = (int*)malloc(n * sizeof(int));
        int* b = (int*)malloc(m * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        int result = twoStacks(maxSum, n, a, m, b);
        printf("%d\n", result);

        free(a);
        free(b);
    }

    return 0;
}