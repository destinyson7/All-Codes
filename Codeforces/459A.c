#include<stdio.h>
#include<stdlib.h>
#define ll long long int

int main()
{
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

	if(x2!=x1 && y2!=y1)
	{
		if((abs(x2-x1))!=(abs(y2-y1)))
			printf("-1");

		else
		{
			x3=x2;
			y3=y1;
			x4=x1;
			y4=y2;

			printf("%lld %lld %lld %lld", x3, y3, x4, y4);
		}
	}

	else
	{
		if(x1==x2)
		{
			x3=x1+(y2-y1);
			y3=y1;
			x4=x3;
			y4=y2;

			printf("%lld %lld %lld %lld", x3, y3, x4, y4);
		}

		else
		{
			y3=y1+(x2-x1);
			x3=x1;
			y4=y3;
			x4=x2;

			printf("%lld %lld %lld %lld", x3, y3, x4, y4);
		}
	}

	return 0;
}