#include <stdio.h>
#include <limits.h>
#define N 9
int minK(int k[], int mst[]) {
    int m = INT_MAX, mi = -1, i;
    for (i = 0; i < N; i++)
        if (!mst[i] && k[i] < m) m = k[i], mi = i;
    return mi;
}
void prim(int g[N][N]) {
    int p[N], k[N], mst[N], i, j;
    for (i = 0; i < N; i++) k[i] = INT_MAX, mst[i] = 0;
    k[0] = 0, p[0] = -1;
    for (i = 0; i < N - 1; i++) {
        int u = minK(k, mst);
        mst[u] = 1;
        for (j = 0; j < N; j++)
            if (g[u][j] && !mst[j] && g[u][j] < k[j]) p[j] = u, k[j] = g[u][j];
    }
    for (i = 1; i < N; i++) printf("%d - %d\n", p[i], i);
}
int main() {
    int g[N][N] = { { 0,4,0,0,0,0,0,8,0 },
                     { 4,0,8,0,0,0,0,11,0},
					 {0,8,0,7,0,4,0,0,2},
					 { 0,0,7,0,9,14,0,0,0},
                     { 0,0,0,9,0,10,0,0,0},
					 {0,0,4,14,10,0,2,0,0},
					 {0,0,0,0,0,2,0,1,6},
					 {8,11,0,0,0,0,1,0,7},
					 {0,0,2,0,0,0,6,7,0} };
    prim(g);
    return 0;
}
