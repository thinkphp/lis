#include <stdio.h>
#define MAX 100001
#define FIN "scmax.in"
#define FOUT "scmax.out"
 
FILE *fin, *fout;
 
void read();
void dynamicProgramming();
void write();
 
int vec[ MAX ], 
    n, 
    best[ MAX ];
 
int main() {
  
    read();
 
    dynamicProgramming();
 
    write();
 
    return 0;
}
 
void read() {
 
     int i;
 
     fin = fopen(FIN, "r");
 
     fscanf(fin, "%d", &n);
 
     for(i = 1; i <= n; i++) {
 
         fscanf(fin, "%d", &vec[ i ]);
     } 
 
     fclose( fin );  
};
 
void dynamicProgramming() {
 
     int i,
 
         j, 
 
         max;
 
     best[ n ] = 1;
 
     for(i = n - 1; i >= 1; i--) {
 
         max = 0;
 
         for(j = i + 1; j <= n; j++) {
 
                 if(vec[ i ] < vec[ j ] && best[ j ] > max) {
 
                       max = best[ j ];
                 }
         } 
 
         best[ i ] = 1 + max;  
     }
};
 
void write() {
 
  int i, 

      pos, 

      k,

      maxBest;
 
     fout = fopen(FOUT ,"w");
 
     pos = 1;
 
     maxBest = best[ 1 ];
 
     for(i = 2; i <= n; i++) {
 
           if(best[ i ] > maxBest) { 
 
               maxBest = best[ i ];
 
               pos = i;
           }
     }  
 
     fprintf(fout, "%d\n", maxBest);
 
     fprintf(fout, "%d ", vec[ pos ]);
 
     maxBest--;
 
     for(k = pos + 1; k <= n; k++) {
 
           if(best[ k ] == maxBest && vec[ pos ] < vec[ k ]) {
 
              fprintf(fout, "%d ", vec[ k ]);
 
              maxBest--;
           } 
     }
 
     fclose( fout );    
};