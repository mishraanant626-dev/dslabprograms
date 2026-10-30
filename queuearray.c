
#include <stdio.h>
#define MAX 100

int main() {
    int q[MAX], front = 0, rear = -1;
    int ch, x, i;

    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            if(rear == MAX-1)
                printf("Queue Full");
            else {
                printf("Enter value: ");
                scanf("%d", &x);
                q[++rear] = x;
            }
        }
        else if(ch == 2) {
            if(front > rear)
                printf("Queue Empty");
            else {
                printf("Deleted: %d", q[front++]);
                if(front > rear) {
                    front = 0;
                    rear = -1;
                }
            }
        }
        else if(ch == 3) {
            for(i = front; i <= rear; i++)
                printf("%d ", q[i]);
        }

    } while(ch != 0);

    return 0;
}
