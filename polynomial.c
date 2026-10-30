
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, pow;
    struct node *next;
};

struct node *create() {
    struct node *head = NULL, *tail = NULL, *p;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p = malloc(sizeof(struct node));

        printf("Enter coefficient and power: ");
        scanf("%d%d", &p->coeff, &p->pow);

        p->next = NULL;

        if(head == NULL)
            head = p;
        else
            tail->next = p;

        tail = p;
    }

    return head;
}

void display(struct node *p) {
    while(p != NULL) {
        printf("%dx^%d", p->coeff, p->pow);
        if(p->next != NULL)
            printf(" + ");
        p = p->next;
    }
}

int main() {
    struct node *a, *b, *c = NULL;
    struct node *tail = NULL, *p;

    printf("First polynomial:\n");
    a = create();

    printf("Second polynomial:\n");
    b = create();

    while(a != NULL && b != NULL) {
        p = malloc(sizeof(struct node));
        p->next = NULL;

        if(a->pow == b->pow) {
            p->coeff = a->coeff + b->coeff;
            p->pow = a->pow;
            a = a->next;
            b = b->next;
        }
        else if(a->pow > b->pow) {
            p->coeff = a->coeff;
            p->pow = a->pow;
            a = a->next;
        }
        else {
            p->coeff = b->coeff;
            p->pow = b->pow;
            b = b->next;
        }

        if(c == NULL)
            c = p;
        else
            tail->next = p;

        tail = p;
    }

    while(a != NULL || b != NULL) {
        p = malloc(sizeof(struct node));
        p->next = NULL;

        if(a != NULL) {
            p->coeff = a->coeff;
            p->pow = a->pow;
            a = a->next;
        }
        else {
            p->coeff = b->coeff;
            p->pow = b->pow;
            b = b->next;
        }

        if(c == NULL)
            c = p;
        else
            tail->next = p;

        tail = p;
    }

    printf("Sum = ");
    display(c);

    return 0;
}
