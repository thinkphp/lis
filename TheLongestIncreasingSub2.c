/* 
   Dynamic Programming C/C++ implementation of LIS problem 
   HackerRank Problem Statement.
   The DP Solution has n^2 Complexity Time and to pass all the test a non_DP solution is required! 
*/
#include<stdio.h>
#include<stdlib.h>

int maxx(int a, int b) {return (a > b) ? a : b;}
/* 
lis() returns the length of the longest increasing
subsequence in arr[] of size n 
*/
int lis( int arr[], int n )
{
	int *lis, i, j, max = 0;
	lis = (int*) malloc ( sizeof( int ) * n );

	/* Initialize LIS values for all indexes */
	for (i = 0; i < n; i++ )
		lis[i] = 1;

	/* Compute optimized LIS values in bottom up manner */
	for (i = 1; i < n; i++ )
		for (j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	/* Pick maximum of all LIS values */
	for (i = 0; i < n; i++ )
		max = maxx(lis[i], max);

	/* Free memory to avoid memory leak */
	free(lis);

	return max;
}


int main()
{
	// Note that size of arr[] is considered 100 according to
    // the constraints mentioned in problem statement.
    int arr[1000000], t, n, i;

        // Input the size of the array
        scanf("%d", &n); 
 
        // Input the array
        for (i=0; i<n; i++)
           scanf("%d",&arr[i]);
 
        // Compute and print result
        printf("%d\n", lis(arr, n));   
    return 0;
}
