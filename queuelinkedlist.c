
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *front = NULL, *rear = NULL, *p;
    int ch, x;

    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            p = malloc(sizeof(struct node));

            printf("Enter value: ");
            scanf("%d", &x);

            p->data = x;
            p->next = NULL;

            if(rear == NULL)
                front = rear = p;
            else {
                rear->next = p;
                rear = p;
            }
        }
        else if(ch == 2) {
            if(front == NULL)
                printf("Queue Empty");
            else {
                p = front;
                printf("Deleted: %d", p->data);
                front = front->next;

                if(front == NULL)
                    rear = NULL;

                free(p);
            }
        }
        else if(ch == 3) {
            p = front;
            while(p != NULL) {
                printf("%d ", p->data);
                p = p->next;
            }
        }

    } while(ch != 0);

    return 0;
}
