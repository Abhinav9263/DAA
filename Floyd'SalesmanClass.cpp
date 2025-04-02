#include <stdio.h>
#define INF 9999  

void floyds(int b[5][5]) {
   int i, j, k;
   for (k = 0; k < 5; k++) {
      for (i = 0; i < 5; i++) {
         for (j = 0; j < 5; j++) {
            if (b[i][k] != INF && b[k][j] != INF) { 
               if (b[i][k] + b[k][j] < b[i][j]) {
                  b[i][j] = b[i][k] + b[k][j];
               }
            }
         }
      }
   }

   for (i = 0; i < 5; i++) {
      printf("Minimum Cost With Respect to Node %d:\n", i);
      for (j = 0; j < 5; j++) {
         if (b[i][j] == INF)
            printf("INF\t");
         else
            printf("%d\t", b[i][j]);
      }
      printf("\n");
   }
}

int main() {
   int b[5][5] = {
       {0,3,8,INF,-4},
       {INF,0,INF,1,7},
       {INF,4,0,INF,INF},
       {2,INF,-5,0,INF},
       {INF,INF,INF,6,0}
   };

   floyds(b);
   return 0;
}
