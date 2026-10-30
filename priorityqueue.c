
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data, priority;
    struct node *next;
};

int main() {
    struct node *front = NULL, *p, *temp;
    int ch, x, pr;

    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            p = malloc(sizeof(struct node));

            printf("Enter data: ");
            scanf("%d", &x);

            printf("Enter priority: ");
            scanf("%d", &pr);

            p->data = x;
            p->priority = pr;
            p->next = NULL;

            if(front == NULL || pr < front->priority) {
                p->next = front;
                front = p;
            }
            else {
                temp = front;

                while(temp->next != NULL &&
                      temp->next->priority <= pr)
                    temp = temp->next;

                p->next = temp->next;
                temp->next = p;
            }
        }
        else if(ch == 2) {
            if(front == NULL)
                printf("Queue Empty");
            else {
                temp = front;
                printf("Deleted: %d", temp->data);
                front = front->next;
                free(temp);
            }
        }
        else if(ch == 3) {
            temp = front;
            while(temp != NULL) {
                printf("\nData: %d Priority: %d",
                       temp->data, temp->priority);
                temp = temp->next;
            }
        }

    } while(ch != 0);

    return 0;
}
