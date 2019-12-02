#include<stdio.h>

int main()
{
    int T, i;
    long long int N, codd=0, ceven=0, j, k, l, m, p, q, r, s;
    long long int arr[100001]={0};

    scanf("%d", &T);

    for(i=0; i<T; i++)
    {
	scanf("%lld", &N);

	for(j=0; j<N; j++)
	    scanf("%lld", &arr[j]);

	for(k=0; k<N; k++)
	{
	    if(arr[j]%2==0)
	    	ceven++;
		
	    else
		codd++;

	}

	for(l=0; l<N; l++)
	{



    return 0;
}
