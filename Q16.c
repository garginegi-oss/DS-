#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int x) {
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

struct Node *insert(struct Node *root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

struct Node *search(struct Node *root, int x) {
    while (root != NULL) {
        if (root->data == x)
            return root;

        if (x < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}

struct Node *findMin(struct Node *root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node *findMax(struct Node *root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

struct Node *deleteNode(struct Node *root, int x) {
    struct Node *temp;

    if (root == NULL)
        return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL, *temp;
    int ch, x;

    do {
        printf("\n1.Insert 2.Delete 3.Search");
        printf("\n4.Minimum 5.Maximum 6.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &x);
                printf("%s\n", search(root, x) != NULL
                       ? "Found" : "Not found");
                break;

            case 4:
                temp = findMin(root);
                if (temp != NULL)
                    printf("Minimum = %d\n", temp->data);
                else
                    printf("Tree is empty\n");
                break;

            case 5:
                temp = findMax(root);
                if (temp != NULL)
                    printf("Maximum = %d\n", temp->data);
                else
                    printf("Tree is empty\n");
                break;

            case 6:
                inorder(root);
                printf("\n");
                break;
        }
    } while (ch != 0);

    return 0;
}