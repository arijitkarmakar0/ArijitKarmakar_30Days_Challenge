#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This helper finds the best window for a specific starting offset
int solve(int k, char* s1, char* s2, int start1, int start2) {
    int max_len = 0, left = 0, right = 0, mismatches = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Slide along this diagonal until we hit the end of either string
    while (start1 + right < len1 && start2 + right < len2) {
        if (s1[start1 + right] != s2[start2 + right]) {
            mismatches++;
        }

        // If we broke the budget (k), move the left side of the window in
        while (mismatches > k) {
            if (s1[start1 + left] != s2[start2 + left]) {
                mismatches--;
            }
            left++;
        }

        // Check if this window is our new record
        int current_window_size = right - left + 1;
        if (current_window_size > max_len) {
            max_len = current_window_size;
        }
        right++;
    }
    return max_len;
}

int substringDiff(int k, char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int global_max = 0;

    // Check all alignments where S1 is shifted
    for (int i = 0; i < n; i++) {
        int res = solve(k, s1, s2, i, 0);
        if (res > global_max) global_max = res;
    }

    // Check all alignments where S2 is shifted
    for (int j = 1; j < m; j++) {
        int res = solve(k, s1, s2, 0, j);
        if (res > global_max) global_max = res;
    }

    return global_max;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int k;
        char s1[1501], s2[1501];
        if (scanf("%d %s %s", &k, s1, s2) == 3) {
            printf("%d\n", substringDiff(k, s1, s2));
        }
    }
    return 0;
}