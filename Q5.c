// (a)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *last = NULL, *p, *temp;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;

        if (head == NULL) {
            head = last = p;
            p->next = head;
        } else {
            p->next = head;
            head = p;
            last->next = head;
        }
    }

    if (head != NULL) {
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("(back to head)");
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
    struct Node *head = NULL, *last = NULL, *p, *temp;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;

        if (head == NULL) {
            head = last = p;
            p->next = head;
        } else {
            last->next = p;
            last = p;
            last->next = head;
        }
    }

    if (head != NULL) {
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("(back to head)");
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
    struct Node *head = NULL, *last = NULL, *p, *temp;
    int n, x, pos, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;

        if (head == NULL) {
            head = last = p;
            p->next = head;
        } else {
            last->next = p;
            last = p;
            last->next = head;
        }
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
        if (head == NULL) {
            head = last = p;
            p->next = head;
        } else {
            p->next = head;
            head = p;
            last->next = head;
        }
    } else {
        temp = head;
        for (i = 1; i < pos - 1; i++)
            temp = temp->next;

        p->next = temp->next;
        temp->next = p;

        if (temp == last)
            last = p;
    }

    if (head != NULL) {
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("(back to head)");
    return 0;
}


//(d)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *last = NULL, *p, *temp;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;

        if (head == NULL) {
            head = last = p;
            p->next = head;
        } else {
            last->next = p;
            last = p;
            last->next = head;
        }
    }

    if (head == NULL) {
        printf("List is empty");
        return 0;
    }

    if (head == last) {
        free(head);
        head = last = NULL;
    } else {
        temp = head;
        head = head->next;
        last->next = head;
        free(temp);
    }

    if (head != NULL) {
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("(back to head)");
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
    struct Node *head = NULL, *last = NULL, *p, *temp;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;

        if (head == NULL) {
            head = last = p;
            p->next = head;
        } else {
            last->next = p;
            last = p;
            last->next = head;
        }
    }

    if (head == NULL) {
        printf("List is empty");
        return 0;
    }

    if (head == last) {
        free(head);
        head = last = NULL;
    } else {
        temp = head;

        while (temp->next != last)
            temp = temp->next;

        temp->next = head;
        free(last);
        last = temp;
    }

    if (head != NULL) {
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("(back to head)");
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
    struct Node *head = NULL, *last = NULL, *p, *temp, *prev;
    int n, x, pos, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        p = malloc(sizeof(struct Node));
        p->data = x;

        if (head == NULL) {
            head = last = p;
            p->next = head;
        } else {
            last->next = p;
            last = p;
            last->next = head;
        }
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    if (pos == 1) {
        if (head == last) {
            free(head);
            head = last = NULL;
        } else {
            temp = head;
            head = head->next;
            last->next = head;
            free(temp);
        }
    } else {
        temp = head;

        for (i = 1; i < pos - 1; i++)
            temp = temp->next;

        p = temp->next;
        temp->next = p->next;

        if (p == last)
            last = temp;

        free(p);
    }

    if (head != NULL) {
        temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("(back to head)");
    return 0;
}