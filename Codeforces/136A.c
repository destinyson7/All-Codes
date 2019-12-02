#include<stdio.h>

int main()
{
    int n, i, k;
    scanf("%d", &n);
    
    int arr[200], arr2[200];

    for(i=0; i<n; i++)
	scanf("%d", &arr[i]);

    for(i=0; i<n; i++)
	{
	    k=arr[i];
	    arr2[k-1]=i+1;
	}
   


    for(k=0; k<n; k++)
	printf("%d ", arr2[k]);



	

    return 0;
}
