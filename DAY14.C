#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Two stacks
int inStack[MAX], outStack[MAX];
int topIn = -1, topOut = -1;

// Push into inStack
void pushIn(int x) {
    inStack[++topIn] = x;
}

// Push into outStack
void pushOut(int x) {
    outStack[++topOut] = x;
}

// Pop from inStack
int popIn() {
    return inStack[topIn--];
}

// Pop from outStack
int popOut() {
    return outStack[topOut--];
}

// Transfer elements only when needed
void transfer() {
    while (topIn != -1) {
        pushOut(popIn());
    }
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            pushIn(x);
        }
        else if (type == 2) {
            if (topOut == -1) {
                transfer();
            }
            if (topOut != -1) {
                popOut();  // safe pop
            }
        }
        else if (type == 3) {
            if (topOut == -1) {
                transfer();
            }
            if (topOut != -1) {
                printf("%d\n", outStack[topOut]);
            }
        }
    }

    return 0;
}