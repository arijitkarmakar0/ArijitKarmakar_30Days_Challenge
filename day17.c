#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return  1;
    return 0;
}

int flatlandSpaceStations(int n, int c_count, int* c) {
    qsort(c, c_count, sizeof(int), cmp);

    int max_dist = 0;

    /* left edge: distance from city 0 to first station */
    max_dist = c[0];

    /* gaps between consecutive stations */
    for (int i = 1; i < c_count; i++) {
        int gap = (c[i] - c[i - 1]) / 2;
        if (gap > max_dist) {
            max_dist = gap;
        }
    }

    /* right edge: distance from last station to city n-1 */
    int end_dist = (n - 1) - c[c_count - 1];
    if (end_dist > max_dist) {
        max_dist = end_dist;
    }

    return max_dist;
}

int main() {
    int n, m;

    printf("Enter number of cities and number of stations: ");
    scanf("%d %d", &n, &m);

    int* c = malloc(m * sizeof(int));

    printf("Enter station indices: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &c[i]);
    }

    int result = flatlandSpaceStations(n, m, c);

    printf("Maximum distance from any city to nearest station: %d\n", result);

    free(c);
    return 0;
}