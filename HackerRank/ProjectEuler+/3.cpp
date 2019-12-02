using namespace std;

#include <iostream>
#include <cmath>

typedef long long int ll;

ll primes[1000005];

void Sieve()
{
	primes[0]=1;
	primes[1]=1;

	for(ll i=2; i<=1000000; i++)
	{
		if(primes[i]==0)
		{
			for(ll j=i; j<=1000000; j+=i)
			{
				primes[j]=1;
			}
		}
	}
}

int main()
{
	ll T;
	cin >> T;

	Sieve();

	while(T--)
	{
		ll N;
		cin >> N;

		ll ans;

		while(N%2==0)
		{
			N/=2;

			if(N==1)
			{
				ans = 2;
				break;
			}
		}

		ll i;
		for(i=3; i<=sqrt(N); i+=2)
		{
			// cout << primes[i];
			// if(primes[i]==0)
			// {
				while(N%i==0)
				{
					N/=i;
					// cout << "N " << N << endl;
				}

				if(N==1)
				{
					ans = i;
					break;
				}
			// }
		}

		if(N>2)
		{
			ans = N;
		}

		else
		{
			ans = i;
		}

		cout << ans << endl;
	}

	return 0;
}