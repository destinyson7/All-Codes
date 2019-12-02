#include<stdio.h>

int main()
{
    int n, p=0;
    int arr[200];
    long long int sum=0, sum2=0;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
	scanf("%d", &arr[i]);

    for(int j=0; j<n-1; j++)
    {
	for(int k=1; k<n; k++)
	{
	    if(arr[k] > arr[k-1])
	    {
		arr[k]=arr[k]^arr[k-1];
		arr[k-1]=arr[k]^arr[k-1];
		arr[k]=arr[k]^arr[k-1];
	    }
	}
    }

    for(int m=0; m<n; m++)
	sum+=arr[m];

    for(int l=0; l<n; l++)
    {
	if(sum2>(sum/2))
	    break;

	else
	{
	    sum2+=arr[l];
	    p++;
	}
		
    }

    printf("%d", p);




    return 0;
}
