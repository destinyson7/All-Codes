#include<stdio.h>
long long int arr[100005];

int main()
{
    long long int n, m;
    scanf("%lld %lld", &n, &m);

    for(long long int i=1; i<=m; i++)
    {
	scanf("%lld", &arr[i]);
    }
	
    long long int time=arr[1]-1;

    for(long long int j=2; j<=m; j++)
    {
	if(arr[j]>=arr[j-1])
	{
	    time+=(arr[j]-arr[j-1]);		
	}

	else
	{
	    time+=(n-(arr[j-1]-arr[j]));
	}
    }

    printf("%lld", time);

    return 0;
}
