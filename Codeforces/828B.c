#include<stdio.h>

typedef long long int ll;
char s[105][105];

int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);

	for(ll i=0; i<n; i++)
	{
		scanf("%s", s[i]);
	}

	ll left=m-1, right=0, top=n-1, bottom=0, flag=0, cntB=0;

	for(ll j=0; j<n; j++)
	{
		for(ll k=0; k<m; k++)
		{
			if(s[j][k]=='B')
			{
				if(j<top)
				{
					top=j;
					flag++;
				}

				if(k<left)
				{
					left=k;
					flag++;
				}

				if(k>right)
				{
					right=k;
					flag++;
				}

				if(j>bottom)
				{
					bottom=j;
					flag++;
				}
				
				// printf("top =%lld bottom=%lld left=%lld right=%lld\n", top, bottom, left, right);

				cntB++;
			}
		}
	}

	// printf("top =%lld\nbottom=%lld\nleft=%lld\nright=%lld\n", top, bottom, left, right);
	ll a = bottom - top;
	ll b = right - left;	

	if(bottom - top > right - left)
	{
		b=a^b;
		a=a^b;
		b=a^b;
	}

	// printf("cntB is %lld\n", cntB);
	// printf("%lld %lld ", right, left);
	
	ll ans = b+1;

	if(ans>n|| ans>m)
	{
		printf("-1\n");
	}

	else
	{
		if(cntB==0)
		{
			printf("1\n");
		}

		else
		{
			printf("%lld\n", ans*ans - cntB);
		}
	}

	return 0;
}