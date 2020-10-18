#include <stdio.h>

int v[7] = {1, 50, 3, 10, 7, 40, 80};

int main(int argc, char const *argv[])
{
	
	int i,
	    k, 
	    max, maxp, pos;
   
    int n = sizeof( v )/sizeof(v[ 0 ]);

    int L[ n ];

    L[ n - 1 ] = 1;

    for(i = n - 2; i >= 0; i--) {

        max = 0;

        for(k = i + 1; k < n; ++k) {

        	if(v[k] > v[i] && L[k] > max) {
 
               max = L[k];
        	}
        }

        L[i] = 1 + max; 
    }  

    printf("\n%s", "L => ");

    for(i = 0; i < n; ++i) printf("%d ", L[i]);

    maxp = L[0]; pos = 0;

    for(i = 1; i < n; ++i) {

    	if(L[i] > maxp) maxp = L[i], pos = i;
    }  

    printf("Len LIS Longest Increasing Subsequence = %d , pos = %d", maxp, pos);

    //display the subsequnce
    printf("\n The Subsequence is -> %d ", v[pos]);

    for(i = pos + 1; i < n; ++i) {

        if(v[i] > v[pos] && maxp - 1 == L[i]) {

           printf("%d ", v[i]); maxp--;  
        }

    }
     

	return 0;
    }
