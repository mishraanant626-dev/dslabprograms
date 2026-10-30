
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

void insert() {
    struct node *p = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &p->data);

    if(last == NULL) {
        last = p;
        p->next = p;
    }
    else {
        p->next = last->next;
        last->next = p;
        last = p;
    }
}

void display() {
    struct node *temp;

    if(last == NULL) {
        printf("List is empty");
        return;
    }

    temp = last->next;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != last->next);

    printf("Back to first node");
}

void delete() {
    struct node *temp, *prev;
    int x;

    if(last == NULL) {
        printf("List is empty");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &x);

    prev = last;
    temp = last->next;

    do {
        if(temp->data == x) {
            if(temp == last && temp == last->next)
                last = NULL;
            else {
                prev->next = temp->next;
                if(temp == last)
                    last = prev;
            }

            free(temp);
            printf("Deleted successfully");
            return;
        }

        prev = temp;
        temp = temp->next;

    } while(temp != last->next);

    printf("Element not found");
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
