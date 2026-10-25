#include <stdio.h>
// (i)(a)
int main() {
    int a[100], n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    for (i = n; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = x;
    n++;

    printf("Array after insertion: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

// (ii)(a)
#include <stdio.h>

int main() {
    int a[100], n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    a[n] = x;
    n++;

    printf("Array after insertion: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

// (iii)(a)
#include <stdio.h>

int main() {
    int a[100], n, i, x, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element and position: ");
    scanf("%d%d", &x, &pos);

    if (pos < 1 || pos > n + 1 || n >= 100) {
        printf("Invalid position or full array");
        return 0;
    }

    for (i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;
    n++;

    printf("Array after insertion: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

// (b)(i)
#include <stdio.h>

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n == 0) {
        printf("Array is empty");
        return 0;
    }

    for (i = 0; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;

    printf("Array after deletion: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

// (b)(ii)
#include <stdio.h>

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n == 0) {
        printf("Array is empty");
        return 0;
    }

    n--;

    printf("Array after deletion: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

// (b)(iii)
#include <stdio.h>

int main() {
    int a[100], n, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    for (i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;

    printf("Array after deletion: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

