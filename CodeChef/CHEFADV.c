#include<stdio.h>

int main()
{
    long long  int T;

    scanf("%lld", &T);

    for(long long int i=1; i<=T; i++)
    {
	long long int N, M, X, Y;
	scanf("%lld %lld %lld %lld", &N, &M, &X, &Y);

	if((N>=X) && (M>=Y) && (N-1)%X==0 && (M-1)%Y==0)
	    printf("Chefirnemo\n");

	else if((N>=X) && (M>=Y) && (N-2)%X==0 && (M-2)%Y==0)
	    printf("Chefirnemo\n");

	else
	    printf("Pofik\n");
    }

    return 0;
}
