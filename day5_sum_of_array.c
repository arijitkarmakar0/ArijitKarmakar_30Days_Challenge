#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);          // Read the size of the array
    
    int sum = 0;
    int num;
    
    // Read n integers and add them to sum
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
    }
    
    printf("%d\n", sum);      // Print the final sum
    
    return 0;
}