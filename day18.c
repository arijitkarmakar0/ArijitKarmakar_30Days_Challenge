#include <stdio.h>

char* kangaroo(int x1, int v1, int x2, int v2) {
    
    // If both start at same position
    if (x1 == x2) {
        return "YES";
    }

    // If speeds are same but positions different
    if (v1 == v2) {
        return "NO";
    }

    // If first kangaroo is behind but not faster
    if (x1 < x2 && v1 <= v2) {
        return "NO";
    }

    // If second kangaroo is behind but not faster
    if (x2 < x1 && v2 <= v1) {
        return "NO";
    }

    // Check if they meet at some jump
    if ((x2 - x1) % (v1 - v2) == 0) {
        return "YES";
    }

    return "NO";
}

int main() {
    int x1, v1, x2, v2;

    // Input from user
    scanf("%d %d %d %d", &x1, &v1, &x2, &v2);

    // Call function
    char* result = kangaroo(x1, v1, x2, v2);

    // Output result
    printf("%s\n", result);

    return 0;
}