using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long int ll;

ll primes[10000005];
ll ans[10000005];

void Sieve()
{
	primes[0]=1;
	primes[1]=1;

	ll cnt=0;
	for(ll i=2; i<10000005; i++)
	{
		if(primes[i]==0)
		{
			ans[cnt++]=i;

			for(ll j=2*i; j<10000005; j+=i)
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

		cout << ans[N-1] << endl;
	}

	return 0;
}