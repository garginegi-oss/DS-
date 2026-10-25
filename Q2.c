// (a)
#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int n, i, j, k;

    printf("Enter order of matrices: ");
    scanf("%d", &n);

    printf("Enter first matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter second matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;

            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Product matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", c[i][j]);

        printf("\n");
    }

    return 0;
}


// (b) 

#include <stdio.h>

int main() {
    int a[10][10], n, i, j;
    int mainSum = 0, secondarySum = 0;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++) {
        mainSum += a[i][i];
        secondarySum += a[i][n - 1 - i];
    }

    printf("Main diagonal sum = %d\n", mainSum);
    printf("Secondary diagonal sum = %d\n", secondarySum);
    printf("Difference = %d\n", mainSum - secondarySum);

    return 0;
}



