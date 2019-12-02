#include<stdio.h>

int main()
{
	long long int n, p1, p2, x[105], y[105];
	scanf("%lld", &n);

	scanf("%lld", &p1);

	long long int s[105]={0};

	for(long long int i=0; i<p1; i++)
	{	
		scanf("%lld", &x[i]);
		s[x[i]]=1;
	}
	
	scanf("%lld", &p2);

	for(long long int j=0; j<p2; j++)
	{
		scanf("%lld", &y[j]);
		s[y[j]]=1;
	}

	int flag=0;

	for(int k=1; k<=n; k++)
	{
		if(s[k]!=1)
		{
			flag=1;
			break;
		}
	}

	if(flag==0)
		printf("I become the guy.");

	else
		printf("Oh, my keyboard!");

	return 0;
}