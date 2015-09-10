#include <stdio.h>
#define FIN "longest.in"
#define FOUT "longest.out"
#define DIMN 100010
 
FILE *fin,
     *fout;
 
int V[ DIMN ], L[ DIMN ], SOL[ DIMN ],
    N,
    i, p, p2, j;
 
void read() {
 
     int i;
 
     fin = fopen(FIN, "r");
 
     fscanf(fin,"%d", &N);
 
     for(i = 1; i <= N; ++i ){
 
         fscanf(fin, "%d", &V[ i ]);
     }

     fclose( fin );
};

int bsearch(int lo, int hi, int x) {
    int m;
    while(lo<=hi) {
          m = (lo+hi)>>1;
          if(SOL[m] < x) lo = m + 1;
                else     hi = m - 1; 
    }
    return lo; 
};

inline int max(int a, int b) {
    if(a>b) return a;
       else return b;
}
 
void solve() {

     fout = fopen(FOUT, "w");

     SOL[ 1 ] = V[ 1 ];

     p = 1; L[ 1 ] = 1;

     for(i = 2; i <= N; i++) {

         j = bsearch(1, p, V[ i ]); L[ i ] = j;

         SOL[ j ] = V[ i ]; p = max(p, j);
     }

     p2 = p; 

     for(i = N; i >= 1; --i)

         if(L[ i ] == p) {SOL[ p ] = V[ i ]; p--;}          

     fprintf(fout, "%d\n", p2);

     for(i = 1; i <= p2; i++) fprintf(fout, "%d ", SOL[ i ]);

     fclose( fout );
 
};
 
int main() {
 
    read();
    solve();
 
 return(0);
};