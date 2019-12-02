#include<stdio.h>
#define int long long int

#undef int

int main()
{
	#define int long long int

	int s, n;
	scanf("%lld %lld", &s, &n);

	int x[1005]={0}, y[1005]={0};

	for(int i=1; i<=n; i++)
	{		
		scanf("%lld %lld", &x[i], &y[i]);
	}

	for(int j=1; j<=n; j++)
	{
		for(int k=1; k<=n-j; k++)
		{
			if(x[k]>x[k+1])
			{
				x[k]=x[k]^x[k+1];
				x[k+1]=x[k]^x[k+1];
				x[k]=x[k]^x[k+1];

				y[k]=y[k]^y[k+1];
				y[k+1]=y[k]^y[k+1];
				y[k]=y[k]^y[k+1];
			}
		}
	}

	// for(int b=1; b<=n; b++)
		// printf("%lld %lld\n", x[b], y[b]);

	int flag=0;
	for(int a=1; a<=n; a++)
	{
		// printf("%lld %lld %lld\n", s, y[a], x[a]);

		if(s<=x[a])
		{	
			flag=1;
			break;
		}

		s=s+y[a];

	}

	if(flag==0)
	{
		printf("YES");
	}

	else
	{
		printf("NO");
	}

	return 0;
}