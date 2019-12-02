#include<stdio.h>
long long int arr[1005];

int main()
{
    long long int n, l;
    scanf("%lld %lld", &n, &l);

    for(long long int i=0; i<n; i++)
    {
	scanf("%lld", &arr[i]);    
    }

    for(long long int j=0; j<n; j++)
    {
	for(long long int k=0; k<n-j-1; k++)
	{
	    if(arr[k+1]<arr[k])
	    {
		arr[k]=arr[k]^arr[k+1];
		arr[k+1]=arr[k]^arr[k+1];
		arr[k]=arr[k]^arr[k+1];
	    }
	}

//	printf("%lld ", arr[j]);
    
    }

    long long int max=2*arr[0];

    for(long long int a=1; a<n; a++)
    {
	if(arr[a]-arr[a-1] > max)
	{
	    max= arr[a] - arr[a-1];
	}

//	printf("%lld ", max);
    }

    if((2*(l - arr[n-1])) > max)
    {
	max= 2*(l - arr[n-1]);
//	printf("%lld ", max);
    }

    long double max2= max;

    long double d=max2/2;   

    printf("%Lf", d);

	
    
    return 0;
}
