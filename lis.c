/**
 *  Longest Incresing Subsequence
 *
 */
#include <stdio.h>

int i, 
    j, 
    n,    
    max, 
    v[20] = {4,1,7,6,7},
    L[20];  

FILE *fin,*fout;

void read();
void readFromFile(const char *);
void solve_dynamic_programming();
void display();

int main() {

    //read the data
    //read();

    readFromFile("lis.in");

    //solve the problem with dynamic programming
    solve_dynamic_programming();    
  
    //display the results
    display();

    return(0);
}

void read() {

    printf("n=");
    scanf("%d",&n); 

    for(i=0;i<n;i++) {

        printf("v[%d]=",i); 
        scanf("%d",&v[i]);          
    }
}

//if you want we can read from File
void readFromFile(const char *filename) {

    fin = fopen(filename, "r");

    fscanf(fin, "%d", &n); 
     
    for( i = 0; i < n; i++) {

        fscanf(fin,"%d", &v[ i ]);
    }

    fclose( fin );
}


void solve_dynamic_programming() {

    L[ n - 1 ] = 1;

    for(i = n - 2; i >= 0; i--) {

        max = 0; 

        for(j = i + 1; j <= n - 1; j++) {

            if(v[ i ] <= v[ j ] && L[ j ] > max) {

               max = L[ j ];
            }
        }
            L[ i ] = 1 + max;
    }  
}

void display() {

    int k;
    //first we start with first slot
    max = L[0];

    fout = fopen("lis.out","w");

    //pos of the maximum
    int pos = 0;

    for(i = 1; i < n; i++) {

        if(L[ i ] > max) { 

           max = L[ i ];

           pos = i;
        } 
    }   

    printf("Longest Increasing SubSequence Length -> %d", max);

    fprintf(fout,"Longest Increasing Subsequence %d", max);

    printf("\n%d ", v[ pos ]);

    fprintf(fout,"\n%d ", v[ pos ]);

    max--;
    
    for(k = pos + 1; k < n; k++) {

        if(L[ k ] == max && v[k] >= v[ pos ]) {

           printf("%d ",v[ k ]);

           fprintf(fout, "%d ", v[ k ]);

           max--;
        }
    }    

    fclose( fout );
}