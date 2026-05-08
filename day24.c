#include <stdio.h>
#include <stdlib.h>

long largestRectangle(int h_count, int* h) {

    int* stack = (int*)malloc(sizeof(int) * (h_count + 1));
    int top = -1;

    long maxArea = 0;
    int i = 0;

    while (i < h_count) {

        if (top == -1 || h[stack[top]] <= h[i]) {
            stack[++top] = i;
            i++;
        } 
        else {

            int height = h[stack[top--]];

            long width;

            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            long area = (long)height * width;

            if (area > maxArea)
                maxArea = area;
        }
    }

    while (top != -1) {

        int height = h[stack[top--]];

        long width;

        if (top == -1)
            width = i;
        else
            width = i - stack[top] - 1;

        long area = (long)height * width;

        if (area > maxArea)
            maxArea = area;
    }

    free(stack);

    return maxArea;
}

int main() {

    int n;

    scanf("%d", &n);

    int* h = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    long result = largestRectangle(n, h);

    printf("%ld\n", result);

    free(h);

    return 0;
}