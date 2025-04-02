#include <stdio.h>
#include <limits.h>

int tsp_g[10][10] = {
   {12, 30, 33, 10, 45},
   {56, 22, 9, 15, 18},
   {29, 13, 8, 5, 12},
   {33, 28, 16, 10, 3},
   {1, 4, 30, 24, 20}
};
int visited[10] = {0}, n = 5, cost = 0, nodes_visited = 0;

void travellingsalesman(int current_city) {
    int k, next_city = -1, min_cost = INT_MAX;

    visited[current_city] = 1;
    nodes_visited++;
    printf("%d ", current_city + 1);

    if (nodes_visited == n) {
        cost += tsp_g[current_city][0];
        printf("%d", 1);
        return;
    }

    for (k = 0; k < n; k++) {
        if (tsp_g[current_city][k] != 0 && !visited[k] && tsp_g[current_city][k] < min_cost) {
            min_cost = tsp_g[current_city][k];
            next_city = k;
        }
    }

    if (next_city != -1) {
        cost += min_cost;
        travellingsalesman(next_city);
    }
}

int main() {
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Shortest Path: ");
    travellingsalesman(0);
    printf("\nMinimum Cost: %d\n", cost);
    
    return 0;
}
