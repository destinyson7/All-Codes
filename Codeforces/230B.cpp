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
			for(ll j=2*i; j<=1000000; j+=i)
			{
				primes[j]=1;
			}
		}
	}
}

int main()
{
	ll n;
	cin >> n;

	Sieve();

	while(n--)
	{
		ll num;
		cin >> num;

		double a = (double)(sqrt(num));
		double b = (ll)(sqrt(num));
		ll c = (ll)b;	
		
		if(a==b)
		{
			if(primes[c]==0)
			{
				cout << "YES" << endl;
			}

			else
			{
				cout << "NO" << endl;
			}
		}

		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}