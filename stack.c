
#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX], top = -1, ch, x, i;

    do {
        printf("\n1.Push\n2.Pop\n3.Display\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            if(top == MAX-1)
                printf("Stack Overflow");
            else {
                printf("Enter value: ");
                scanf("%d", &x);
                stack[++top] = x;
            }
        }
        else if(ch == 2) {
            if(top == -1)
                printf("Stack Underflow");
            else
                printf("Deleted: %d", stack[top--]);
        }
        else if(ch == 3) {
            for(i = top; i >= 0; i--)
                printf("%d\n", stack[i]);
        }

    } while(ch != 0);

    return 0;
}
