#include<stdio.h>

typedef long long int ll;

int main()
{
	ll n;
	scanf("%lld", &n);

	char s[1005];
	scanf("%s", s);

	ll flag=0;
	for(ll i=0; i<n-1; i++)
	{
		if(s[i]!=s[i+1])
		{
			printf("YES\n");
			printf("%c%c\n", s[i], s[i+1]);
			flag=1;
			break;
		}
	}	

	if(flag==0)
	{
		printf("NO\n");
	}


	return 0;
}