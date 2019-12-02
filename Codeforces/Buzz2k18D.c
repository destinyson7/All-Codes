#include<stdio.h>
#include<math.h>

long long int xset[1000];
long long int yset[1000];
long long int sumset[1000000];

void merge(long long int arr[], long long int l, long long int m, long long int r) 
{ 
    long long int i, j, k; 
    long long int n1 = m - l + 1; 
    long long int n2 =  r - m; 
  
    /* create temp arrays */
    long long int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(long long int arr[], long long int l, long long int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        long long int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(long long int A[], long long int size) 
{ 
    long long int i; 
    for (i=0; i < size; i++) 
        printf("%lld ", A[i]); 
    printf("\n"); 
} 

int main()
{
	long long int x, y, l, r;
	scanf("%lld %lld %lld %lld", &x, &y, &l, &r);

	long long int cntx=0, cnty=0, cnt=0, least, max;

	for(long long int i=0;; i++)
	{
		if(pow(x,i)>pow(10,18) || pow(x,i)<0)
			break;

		xset[i]=pow(x,i);
		cntx++;
	}

	for(long long int j=0;; j++)
	{
		if(pow(y,j)>pow(10,18) || pow(y,j)<0)
			break;

		yset[j]=pow(y,j);
		cnty++;
	}

	for(long long int i=0; i<=cntx; i++)
	{
		for(long long int j=0; j<=cnty; j++)
		{
			sumset[cnt++]=xset[i]+yset[j];
		}
	}	

	mergeSort(sumset, 0, cnt);
	// printArray(sumset, cnt);

	for(long long int i=0; i<=cnt; i++)
	{
		least=i;

		if(sumset[i]>=l)
		{
			// least=i;
			break;
		}

	}

	for(long long int i=0; i<=cnt; i++)
	{
		if(i)
			max=i-1;

		if(sumset[i]>r)
		{
			// max=i-1;
			break;
		}
	}

	long long int maxdif= sumset[least+1] - sumset[least] - 1; 

	for(long long int j=least; j<max; j++)
	{
		if(sumset[j+1]-sumset[j]-1 > maxdif)
		{
			maxdif=sumset[j+1]-sumset[j]-1;
		}
	}

	printf("%lld\n", maxdif);

	return 0;
}