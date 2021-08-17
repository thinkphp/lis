#include <iostream>
#define FIN "scmax.in"
#define FOUT "scmax.out"
#define INF 2000000005
#define NMAX 100005

using namespace std;

int v[ NMAX ], N,
    p[ NMAX ], q[ NMAX ], s[ NMAX ], NR;

int insert(int val, int left, int right) {

    int m = (left + right) >> 1;

    if(left == right) {
             if(right > NR) {
                q[++NR + 1] = INF;
             }
             q[left] = val;
             return left;
    } else {

           if(val<=q[m]) {
              return insert(val, left, m);
           } else {
             return insert(val, m + 1, right);
           }
    }
}

void build() {

     int i;

     q[ 1 ] = INF;

     for(i = 1; i <= N; i++) {

         p[ i ] = insert(v[ i ], 1, NR + 1);
     }
}

void sol() {

     int i, k;

     for(k = N, i = NR; i; i--) {

            while(p[k] != i) k--;

            s[i] = v[k];
     }

     cout<<NR<<"\n";

     for(i = 1; i <= NR; i++) cout<<s[i]<<" ";

     cout<<"\n";
}

int main( int argc, char const *argv[] ) {

  freopen(FIN, "r", stdin);
  freopen(FOUT, "w", stdout);

  cin>>N;

  for(int i = 1; i <= N; ++i) {

      cin>>v[ i ];

  }

  build( );

  sol();

  return 0;
}
