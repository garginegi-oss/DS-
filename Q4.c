//(a)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

int main() {
    struct Node *head = NULL, *p, *temp;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;
        p->prev = NULL;
        p->next = head;

        if (head != NULL)
            head->prev = p;

        head = p;
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d <-> ", temp->data);

    printf("NULL");
    return 0;
}

// (b)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

int main() {
    struct Node *head = NULL, *p, *temp;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;
        p->next = NULL;

        if (head == NULL) {
            p->prev = NULL;
            head = p;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = p;
            p->prev = temp;
        }
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d <-> ", temp->data);

    printf("NULL");
    return 0;
}

// (c)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

int main() {
    struct Node *head = NULL, *p, *temp;
    int n, x, pos, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;
        p->prev = NULL;
        p->next = head;

        if (head != NULL)
            head->prev = p;
        head = p;
    }

    printf("Enter value and position: ");
    scanf("%d%d", &x, &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position");
        return 0;
    }

    p = malloc(sizeof(struct Node));
    p->data = x;

    if (pos == 1) {
        p->prev = NULL;
        p->next = head;
        if (head != NULL)
            head->prev = p;
        head = p;
    } else {
        temp = head;
        for (i = 1; i < pos - 1; i++)
            temp = temp->next;

        p->next = temp->next;
        p->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = p;

        temp->next = p;
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d <-> ", temp->data);

    printf("NULL");
    return 0;
}

// (d)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

int main() {
    struct Node *head = NULL, *p, *temp;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;
        p->prev = NULL;
        p->next = head;
        if (head != NULL)
            head->prev = p;
        head = p;
    }

    if (head == NULL) {
        printf("List is empty");
        return 0;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d <-> ", temp->data);

    printf("NULL");
    return 0;
}

//(e)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

int main() {
    struct Node *head = NULL, *p, *temp;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;
        p->prev = NULL;
        p->next = head;
        if (head != NULL)
            head->prev = p;
        head = p;
    }

    if (head == NULL) {
        printf("List is empty");
        return 0;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d <-> ", temp->data);

    printf("NULL");
    return 0;
}


// (f)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

int main() {
    struct Node *head = NULL, *p, *temp;
    int n, x, pos, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;
        p->prev = NULL;
        p->next = head;
        if (head != NULL)
            head->prev = p;
        head = p;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    temp = head;

    for (i = 1; i < pos; i++)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d <-> ", temp->data);

    printf("NULL");
    return 0;
}

