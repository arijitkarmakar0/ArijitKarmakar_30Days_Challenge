#include <stdio.h>
#include <stdlib.h>

#define MAXN 500005
#define MAXQ 15000000 // O(N log N) queries

typedef long long ll;

// Structure to store offline queries for the Fenwick Tree
typedef struct {
    int pos, limit, sign, id;
} Query;

int a[MAXN], L[MAXN], R[MAXN], BIT[MAXN];
int coords[MAXN], unique_coords[MAXN], n_coords;
ll query_results[MAXQ / 2]; // One result per pair of sign queries
Query queries[MAXQ];
int q_count = 0;

// Standard Binary Indexed Tree (Fenwick Tree) functions
void update(int idx, int val, int limit) {
    for (; idx <= limit; idx += idx & -idx) BIT[idx] += val;
}

int queryBIT(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) res += BIT[idx];
    return res;
}

// Comparators for qsort
int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compare_queries(const void* a, const void* b) {
    return (((Query*)a)->pos - ((Query*)b)->pos);
}

// Binary search for coordinate compression
int get_upper_coord(ll val) {
    int low = 0, high = n_coords - 1, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (unique_coords[mid] <= val) {
            ans = mid + 1;
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}

int get_coord(int val) {
    int low = 0, high = n_coords - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (unique_coords[mid] == val) return mid + 1;
        if (unique_coords[mid] < val) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

int stack[MAXN];
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        coords[i - 1] = a[i];
    }

    // 1. Coordinate Compression
    qsort(coords, n, sizeof(int), compare_int);
    n_coords = 0;
    if (n > 0) {
        unique_coords[n_coords++] = coords[0];
        for (int i = 1; i < n; i++) {
            if (coords[i] != coords[i - 1]) unique_coords[n_coords++] = coords[i];
        }
    }

    // 2. Monotonic Stack to find boundaries [L, R]
    int top = -1;
    for (int i = 1; i <= n; i++) {
        while (top >= 0 && a[stack[top]] <= a[i]) top--;
        L[i] = (top == -1) ? 0 : stack[top];
        stack[++top] = i;
    }
    top = -1;
    for (int i = n; i >= 1; i--) {
        while (top >= 0 && a[stack[top]] < a[i]) top--;
        R[i] = (top == -1) ? n + 1 : stack[top];
        stack[++top] = i;
    }

    // 3. Smaller-to-Larger Query Generation
    int res_id = 0;
    for (int m = 1; m <= n; m++) {
        int l = L[m] + 1, r = R[m] - 1;
        if (m - l < r - m) {
            for (int i = l; i <= m; i++) {
                int limit = get_upper_coord((ll)a[m] / a[i]);
                int q_l = (i + 1 > m) ? i + 1 : m, q_r = r;
                if (q_l <= q_r) {
                    queries[q_count++] = (Query){q_l - 1, limit, -1, res_id};
                    queries[q_count++] = (Query){q_r, limit, 1, res_id++};
                }
            }
        } else {
            for (int j = m; j <= r; j++) {
                int limit = get_upper_coord((ll)a[m] / a[j]);
                int q_l = l, q_r = (j - 1 < m) ? j - 1 : m;
                if (q_l <= q_r) {
                    queries[q_count++] = (Query){q_l - 1, limit, -1, res_id};
                    queries[q_count++] = (Query){q_r, limit, 1, res_id++};
                }
            }
        }
    }

    // 4. Offline Sweep with Fenwick Tree
    qsort(queries, q_count, sizeof(Query), compare_queries);
    int curr_pos = 0;
    for (int i = 0; i < q_count; i++) {
        while (curr_pos < queries[i].pos) {
            curr_pos++;
            update(get_coord(a[curr_pos]), 1, n_coords);
        }
        query_results[queries[i].id] += (ll)queries[i].sign * queryBIT(queries[i].limit);
    }

    ll ans = 0;
    for (int i = 0; i < res_id; i++) ans += query_results[i];
    printf("%lld\n", ans);

    return 0;
}