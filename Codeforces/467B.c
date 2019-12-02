#include<stdio.h>
long long int arr[1005];

int main()
{
    long long int n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);

    for(long long int i=0; i<=m; i++)
    {
	scanf("%lld", &arr[i]);
    }

    long long int friends=0;

    for(long long int j=0; j<m; j++)
    {
	long long int cnt=0;
    	arr[j]^=arr[m];

	while(arr[j])
	{
		if(arr[j]&1)
		{
		cnt++;
		}

		arr[j]>>=1;
	}

	if(cnt<=k)
	{
	    friends++;
	}
    }

    printf("%lld", friends);

    return 0;
}
