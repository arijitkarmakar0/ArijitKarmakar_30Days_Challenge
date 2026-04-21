#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global arrays for Fenwick Tree and Coordinate Compression
long long bit[100005];
int sorted_x[100005], counts[100005];
int unique_count = 0;

// Update Fenwick Tree
void update(int idx, int val, int n) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}

// Find k-th element using Binary Lifting on Fenwick Tree
int find_kth(int k, int n) {
    int idx = 0;
    for (int i = 1 << 17; i > 0; i >>= 1) {
        if (idx + i <= n && bit[idx + i] < k) {
            idx += i;
            k -= bit[idx];
        }
    }
    return idx + 1;
}

int compare(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void print_median(int total_elements) {
    if (total_elements == 0) {
        printf("Wrong!\n");
        return;
    }

    if (total_elements % 2 == 1) {
        // Median is the middle element
        int res_idx = find_kth((total_elements + 1) / 2, unique_count);
        printf("%d\n", sorted_x[res_idx - 1]);
    } else {
        // Median is the average of two middle elements
        long long m1 = sorted_x[find_kth(total_elements / 2, unique_count) - 1];
        long long m2 = sorted_x[find_kth(total_elements / 2 + 1, unique_count) - 1];
        long long sum = m1 + m2;
        
        if (sum % 2 == 0) {
            printf("%lld\n", sum / 2);
        } else {
            // Handle .5 formatting: sum/2.0 automatically handles negative .5 (e.g., -0.5)
            printf("%.1f\n", sum / 2.0);
        }
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    char ops[N];
    int vals[N];
    int temp_x[N];

    for (int i = 0; i < N; i++) {
        char s[10];
        scanf("%s %d", s, &vals[i]);
        ops[i] = s[0];
        temp_x[i] = vals[i];
    }

    // 1. Coordinate Compression
    qsort(temp_x, N, sizeof(int), compare);
    for (int i = 0; i < N; i++) {
        if (i == 0 || temp_x[i] != temp_x[i - 1]) {
            sorted_x[unique_count++] = temp_x[i];
        }
    }

    // 2. Process Operations
    int current_size = 0;
    for (int i = 0; i < N; i++) {
        // Find the compressed index of the current value
        int *p = (int*)bsearch(&vals[i], sorted_x, unique_count, sizeof(int), compare);
        int idx = (int)(p - sorted_x) + 1;

        if (ops[i] == 'a') {
            update(idx, 1, unique_count);
            counts[idx]++;
            current_size++;
            print_median(current_size);
        } else {
            if (counts[idx] > 0) {
                update(idx, -1, unique_count);
                counts[idx]--;
                current_size--;
                print_median(current_size);
            } else {
                printf("Wrong!\n");
            }
        }
    }

    return 0;
}