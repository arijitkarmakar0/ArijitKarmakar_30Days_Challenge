#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* isBalanced(char* s) {
    int n = strlen(s);
    char *stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else {
            if (top == -1) {
                free(stack);
                return "NO";
            }

            char open = stack[top--];

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                free(stack);
                return "NO";
            }
        }
    }

    free(stack);
    return (top == -1) ? "YES" : "NO";
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char s[1005];
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }

    return 0;
}