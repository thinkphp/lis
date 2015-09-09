#include <stdio.h>
#define FIN "scmax.in"
#define FOUT "scmax.out"
#define DIMN 100005

FILE *fin,
     *fout;

int V[ DIMN ], L[ DIMN ],
    N;

void read() {

     int i;

     fin = fopen(FIN, "r");

     fscanf(fin,"%d",&N);

     for(i = 1; i <= N; ++i ){

         fscanf(fin,"%d",&V[ i ]);
     }
};

void solve() {

     fout = fopen(FOUT, "w");

     int max, i, k, pos, t;

     L[ N ] = 1;

     for(k = N - 1; k >= 1; --k) {

         max = 0;

         for(i = k + 1; i <= N; ++i) {

                 if(V[ i ] > V[ k ] && L[ i ] > max) {

                    max = L[i ];
                 }
         }

         L[ k ] = 1 + max;
     }

     max = L[ 1 ];

     pos = 1;

     for(i = 2; i <= N; ++i) {

         if(L[ i ] > max) max = L[ i ], pos = i;
     }

     fprintf(fout, "%d\n%d", max, V[ pos ]);

     for(t = pos + 1; t <= N; ++t) {

         if(V[ t ] > V[ pos ] && L[ t ] == max - 1) {

            fprintf(fout, " %d", V[ t ]);

            max--;  
         }
     } 
};

int main() {

    read();
    solve();

 return(0);
};