// (a)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    printf("Linked list: ");
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
    return 0;
}


// (b) 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
    return 0;
}

// (c)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, x, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("Enter value and position: ");
    scanf("%d%d", &x, &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position");
        return 0;
    }

    newNode = malloc(sizeof(struct Node));
    newNode->data = x;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        for (i = 1; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);

    printf("NULL");
    return 0;
}

// (d) 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    if (head == NULL) {
        printf("List is empty");
        return 0;
    }

    temp = head;
    head = head->next;
    free(temp);

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);

    printf("NULL");
    return 0;
}

// (e) 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *prev, *newNode;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    if (head == NULL) {
        printf("List is empty");
        return 0;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        temp = head;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);

    printf("NULL");
    return 0;
}

// (f)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *prev, *newNode;
    int n, x, pos, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    temp = head;

    if (pos == 1) {
        head = head->next;
        free(temp);
    } else {
        for (i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        free(temp);
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);

    printf("NULL");
    return 0;
}

//(g)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    struct Node *prev = NULL, *next;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    temp = head;

    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    head = prev;

    printf("Reversed list: ");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d -> ", temp->data);

    printf("NULL");
    return 0;
}