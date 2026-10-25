#include <stdio.h>

struct Edge {
    int u, v, weight;
};

struct Edge edges[100];
int parent[20];

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int unite(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b)
        return 0;

    parent[a] = b;
    return 1;
}

int main() {
    int n, m, i, j, count = 0, total = 0;
    struct Edge temp;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter edges as: source destination weight\n");

    for (i = 0; i < m; i++)
        scanf("%d%d%d", &edges[i].u,
              &edges[i].v, &edges[i].weight);

    for (i = 0; i < n; i++)
        parent[i] = i;

    /* Sort edges by increasing weight */
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("Edges in minimum spanning tree:\n");

    for (i = 0; i < m && count < n - 1; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            printf("%d - %d : %d\n",
                   edges[i].u, edges[i].v,
                   edges[i].weight);

            total += edges[i].weight;
            count++;
        }
    }

    if (count == n - 1)
        printf("Minimum cost = %d\n", total);
    else
        printf("Graph is disconnected; MST does not exist.\n");

    return 0;
}