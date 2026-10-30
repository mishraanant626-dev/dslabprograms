


#include <stdio.h>
#define MAX 5

int main() {
    int q[MAX], front = -1, rear = -1;
    int ch, x, i;

    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            if((rear+1)%MAX == front)
                printf("Queue Full");
            else {
                printf("Enter value: ");
                scanf("%d", &x);

                if(front == -1)
                    front = 0;

                rear = (rear+1)%MAX;
                q[rear] = x;
            }
        }
        else if(ch == 2) {
            if(front == -1)
                printf("Queue Empty");
            else {
                printf("Deleted: %d", q[front]);

                if(front == rear)
                    front = rear = -1;
                else
                    front = (front+1)%MAX;
            }
        }
        else if(ch == 3) {
            if(front == -1)
                printf("Queue Empty");
            else {
                i = front;
                while(1) {
                    printf("%d ", q[i]);
                    if(i == rear) break;
                    i = (i+1)%MAX;
                }
            }
        }

    } while(ch != 0);

    return 0;
}
