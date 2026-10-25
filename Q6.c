#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};

struct Node *createTerm(int c, int e) {
    struct Node *p = malloc(sizeof(struct Node));
    p->coeff = c;
    p->exp = e;
    p->next = NULL;
    return p;
}

void insertTerm(struct Node **head, int c, int e) {
    struct Node *p = *head, *prev = NULL;

    while (p != NULL && p->exp > e) {
        prev = p;
        p = p->next;
    }

    if (p != NULL && p->exp == e) {
        p->coeff += c;
        return;
    }

    struct Node *newNode = createTerm(c, e);
    newNode->next = p;

    if (prev == NULL)
        *head = newNode;
    else
        prev->next = newNode;
}

struct Node *readPolynomial() {
    struct Node *head = NULL;
    int n, c, e, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        insertTerm(&head, c, e);
    }

    return head;
}

void display(struct Node *p) {
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);
        p = p->next;

        if (p != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *p1, *p2, *temp;

    printf("First polynomial:\n");
    p1 = readPolynomial();

    printf("Second polynomial:\n");
    p2 = readPolynomial();

    for (temp = p2; temp != NULL; temp = temp->next)
        insertTerm(&p1, temp->coeff, temp->exp);

    printf("Sum of polynomials: ");
    display(p1);

    return 0;
}