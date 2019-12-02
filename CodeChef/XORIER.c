#include<stdio.h>

int main()
{
    int T;
    long long int N, cnt=0;
    long long int arr[100001];
	
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
	scanf("%lld", &N);
	
	for(long long int j=0; j<N; j++)
	    scanf("%lld", &arr[j]);

	for(long long int k=0; k<N; k++)
	{

	    for(long long int l=k; l<N; l++)
	    {
		long long int m= (arr[k]^arr[l]);

		if(m!=0 && m!=1 && m!=2 && (m%2==0))
		    cnt++;
	    }

	}
	
	printf("%lld\n", cnt);
	cnt=0;
	
    }

    return 0;
}
