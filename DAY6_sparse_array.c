#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* matchingStrings(int stringList_count, char** stringList, 
                     int queries_count, char** queries, int* result_count) {
    
    *result_count = queries_count;
    int* result = (int*)malloc(queries_count * sizeof(int));
    
    for (int i = 0; i < queries_count; i++) {
        result[i] = 0;
        for (int j = 0; j < stringList_count; j++) {
            if (strcmp(queries[i], stringList[j]) == 0) {
                result[i]++;
            }
        }
    }
    return result;
}

int main() {
    int n, q;
    
    // Read size of stringList
    scanf("%d", &n);
    
    // Read stringList
    char** stringList = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        stringList[i] = (char*)malloc(21 * sizeof(char));
        scanf("%s", stringList[i]);
    }
    
    // Read size of queries
    scanf("%d", &q);
    
    // Read queries
    char** queries = (char**)malloc(q * sizeof(char*));
    for (int i = 0; i < q; i++) {
        queries[i] = (char*)malloc(21 * sizeof(char));
        scanf("%s", queries[i]);
    }
    
    // Call the function
    int res_count;
    int* result = matchingStrings(n, stringList, q, queries, &res_count);
    
    // Print output (one count per line)
    for (int i = 0; i < res_count; i++) {
        printf("%d\n", result[i]);
    }
    
    // Free allocated memory
    for (int i = 0; i < n; i++) free(stringList[i]);
    free(stringList);
    for (int i = 0; i < q; i++) free(queries[i]);
    free(queries);
    free(result);
    
    return 0;
}