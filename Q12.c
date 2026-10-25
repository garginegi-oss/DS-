#include <stdio.h>
#define SIZE 10

int main() {
    int hash[SIZE], n, key, i, index, count;

    for (i = 0; i < SIZE; i++)
        hash[i] = -1;

    printf("Enter number of keys (maximum %d): ", SIZE);
    scanf("%d", &n);

    if (n < 0 || n > SIZE) {
        printf("Invalid number of keys");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);

        index = key % SIZE;
        count = 0;

        while (hash[index] != -1 && count < SIZE) {
            index = (index + 1) % SIZE;
            count++;
        }

        if (count == SIZE) {
            printf("Hash table is full\n");
        } else {
            hash[index] = key;
        }
    }

    printf("\nHash table:\n");
    for (i = 0; i < SIZE; i++)
        printf("Index %d: %d\n", i, hash[i]);

    return 0;
}