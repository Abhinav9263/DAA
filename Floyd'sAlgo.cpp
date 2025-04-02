#include <stdio.h>
#define INF 9999  

void floyds(int b[3][3]) {
   int i, j, k;
   for (k = 0; k < 3; k++) {
      for (i = 0; i < 3; i++) {
         for (j = 0; j < 3; j++) {
            if (b[i][k] != INF && b[k][j] != INF) { 
               if (b[i][k] + b[k][j] < b[i][j]) {
                  b[i][j] = b[i][k] + b[k][j];
               }
            }
         }
      }
   }

   for (i = 0; i < 3; i++) {
      printf("Minimum Cost With Respect to Node %d:\n", i);
      for (j = 0; j < 3; j++) {
         if (b[i][j] == INF)
            printf("INF\t");
         else
            printf("%d\t", b[i][j]);
      }
      printf("\n");
   }
}

int main() {
   int b[3][3] = {
       {0, 10, INF},
       {INF, 0, 15},
       {12, INF, 0}
   };

   floyds(b);
   return 0;
}
