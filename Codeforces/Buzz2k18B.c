#include<stdio.h>

int main()
{ 
	long long int n;
	scanf("%lld", &n);

	// for(int i=2;i<=nos;i++)
	// 	isprime[i]=1;
	// // initially assuming all nos are prime
	// // 'nos' tell upto which number i have to find prime nos
	// // Time Complexity : O(Nlog(logN))
	// for(int i=2;i<=nos;i++)
	// {
	// 	if(isprime[i]==1)
	// 	{
	// 		// striking out which are not prime
	// 		for(int j=2*i;j<=nos;j+=i)
	// 			isprime[j]=0;
	// 	}
	// }

	if(n==0)
	{
		printf("-1");
	}

	else if(n==1)
	{
		printf("-1");
	}

	else if(n==2)
	{
		printf("1\n2");
	}

	else if(n==3)
	{
		printf("1\n3");
	}

	else{
	long long int k;
	
	if(n%2==1)	
	{
		k=n/2;
		k--;
		

		printf("%lld\n", k+1);

		for(long long int i=0; i<k; i++)
		{
			printf("2 ");
		}

		printf("3 ");
	}

	else
	{
		k=n/2;
		printf("%lld\n", k);

		for(long long int j=0; j<k; j++)
			printf("2 ");
	}
	}



	return 0;
}