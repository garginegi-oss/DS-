#include <stdio.h>

int main() {
    int a[100], n, x, i;
    int linear = -1, binary = -1;
    int low, high, mid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    /* Sequential search */
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            linear = i;
            break;
        }
    }

    if (linear == -1)
        printf("Sequential search: Not found\n");
    else
        printf("Sequential search: Found at position %d\n",
               linear + 1);

    /* Binary search */
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (a[mid] == x) {
            binary = mid;
            break;
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (binary == -1)
        printf("Binary search: Not found\n");
    else
        printf("Binary search: Found at position %d\n",
               binary + 1);

    return 0;
}