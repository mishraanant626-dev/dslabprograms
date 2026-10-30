
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *top = NULL, *p;
    int ch, x;

    do {
        printf("\n1.Push\n2.Pop\n3.Display\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            p = malloc(sizeof(struct node));
            printf("Enter value: ");
            scanf("%d", &x);

            p->data = x;
            p->next = top;
            top = p;
        }
        else if(ch == 2) {
            if(top == NULL)
                printf("Stack Underflow");
            else {
                p = top;
                printf("Deleted: %d", p->data);
                top = top->next;
                free(p);
            }
        }
        else if(ch == 3) {
            p = top;
            while(p != NULL) {
                printf("%d\n", p->data);
                p = p->next;
            }
        }

    } while(ch != 0);

    return 0;
}
