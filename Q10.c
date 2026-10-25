#include <stdio.h>

void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n",
               source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n",
           n, source, destination);

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of disks\n");
        return 0;
    }

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}

// (a)
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted element: %d\n", queue[front++]);

        if (front > rear) {
            front = 0;
            rear = -1;
        }
    }
}

void display() {
    int i;

    if (rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main() {
    int ch, x;

    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}

// (b)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *p = malloc(sizeof(struct Node));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    p->data = x;
    p->next = NULL;

    if (rear == NULL) {
        front = rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
}

void dequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void display() {
    struct Node *temp = front;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int ch, x;

    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}

// (c)
#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void enqueue(int x) {
    if (top1 == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    s1[++top1] = x;
}

void dequeue() {
    if (top2 == -1) {
        while (top1 != -1)
            s2[++top2] = s1[top1--];
    }

    if (top2 == -1)
        printf("Queue Underflow\n");
    else
        printf("Deleted element: %d\n", s2[top2--]);
}

int main() {
    int ch, x;

    do {
        printf("\n1.Enqueue 2.Dequeue 0.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x);
        } else if (ch == 2) {
            dequeue();
        }
    } while (ch != 0);

    return 0;
}

