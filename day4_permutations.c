#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s) {
    if (n <= 1) return 0;
    
    // Step 1: Find the rightmost pivot k where s[k] < s[k+1]
    int k = n - 2;
    while (k >= 0 && strcmp(s[k], s[k + 1]) >= 0) {
        k--;
    }
    
    if (k < 0) {
        return 0;  // This is the last permutation
    }
    
    // Step 2: Find the rightmost successor l > k where s[k] < s[l]
    int l = n - 1;
    while (l > k && strcmp(s[k], s[l]) >= 0) {
        l--;
    }
    
    // Step 3: Swap pivot and successor
    char *temp = s[k];
    s[k] = s[l];
    s[l] = temp;
    
    // Step 4: Reverse the suffix after pivot
    int i = k + 1;
    int j = n - 1;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    char **s = (char**)calloc(n, sizeof(char*));
    
    for (int i = 0; i < n; i++) {
        s[i] = (char*)calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }
    
    do {
        for (int i = 0; i < n; i++) {
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
        }
    } while (next_permutation(n, s));
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    
    return 0;
}