
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert() {
    struct node *newnode, *temp;

    newnode = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

void delete() {
    struct node *temp = head, *prev = NULL;
    int x;

    printf("Enter value to delete: ");
    scanf("%d", &x);

    while(temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Element not found");
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Deleted successfully");
}

int main() {
    int ch;

    do {
        printf("\n1.Insert\n2.Display\n3.Delete\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1)
            insert();
        else if(ch == 2)
            display();
        else if(ch == 3)
            delete();

    } while(ch != 0);

    return 0;
}
