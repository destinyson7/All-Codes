#include<stdio.h>
#include<math.h>

// #define pr 1000000

int main()
{
	long long int t;
	scanf("%lld", &t);

	while(t--)
	{
		int d;
		scanf("%d", &d);

		// double d = h;
  //       // printf("%f", d);
		// double a, b, c, e;
		// double D = d*d - 4*d;

		if(d==0)
		{
			printf("Y 0.000000000 0.000000000\n");
		}

		else if(d*d - 4*d<0)
		{
			printf("N\n");
		}

		else
		{
			// a = d + sqrt(D);
			// a/=2;
			// b = d/a;

			printf("Y %.9f %.9f\n", (d + sqrt(d*d-4*d))/2, (d - sqrt(d*d-4*d))/2);
		}
	}	


	return 0;
}