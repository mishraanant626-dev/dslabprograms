
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insert() {
    struct node *p, *temp;
    p = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &p->data);

    p->next = NULL;
    p->prev = NULL;

    if(head == NULL)
        head = p;
    else {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = p;
        p->prev = temp;
    }
}

void display() {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty");
        return;
    }

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void delete() {
    struct node *temp = head;
    int x;

    printf("Enter value to delete: ");
    scanf("%d", &x);

    while(temp != NULL && temp->data != x)
        temp = temp->next;

    if(temp == NULL) {
        printf("Element not found");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Deleted successfully");
}

int main() {
    int ch;

    do {
        printf("\n1.Insert\n2.Display\n3.Delete\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1) insert();
        else if(ch == 2) display();
        else if(ch == 3) delete();

    } while(ch != 0);

    return 0;
}
