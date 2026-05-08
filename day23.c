#include <stdio.h>

#define MAX 1000000

int dp[MAX + 1];

void precompute() {

    for (int i = 0; i <= MAX; i++) {
        dp[i] = i;
    }

    dp[0] = 0;

    for (int i = 1; i <= MAX; i++) {

        // Decrease by 1
        if (i + 1 <= MAX && dp[i + 1] > dp[i] + 1) {
            dp[i + 1] = dp[i] + 1;
        }

        // Factor operation
        for (int j = 2; i * j <= MAX; j++) {

            int num = i * j;
            int next = (i > j) ? i : j;

            if (dp[num] > dp[next] + 1) {
                dp[num] = dp[next] + 1;
            }
        }
    }
}

int downToZero(int n) {
    return dp[n];
}

int main() {

    precompute();

    int q;
    scanf("%d", &q);

    while (q--) {

        int n;
        scanf("%d", &n);

        printf("%d\n", downToZero(n));
    }

    return 0;
}