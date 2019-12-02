using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long int ll;

ll primes[50];
ll ans[50];

void Sieve()
{
	primes[0]=1;
	primes[1]=1;

	for(ll i=2; i<=40; i++)
	{
		if(primes[i]==0)
		{
			for(ll j= 2*i; j<=40; j+=i)
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

		ll temp[50];

		for(ll k=0; k<50; k++)
		{
			ans[k]=0;
		}

		for(ll i=2; i<=N; i++)
		{
			for(ll k=0; k<50; k++)
			{
				temp[k]=0;
			}

			for(ll j=2; j<=i; j++)
			{
				if(primes[j]==0)
				{
					ll tempo = i;
					while(tempo%j==0)
					{
						temp[j]++;
						tempo/=j;
					}
				}

				ans[j]=max(temp[j], ans[j]);
			}
		}

		ll pr = 1;

		for(ll m=2; m<=N; m++)
		{
			pr*=pow(m, ans[m]);
		}

		cout << pr << endl;
	}

	return 0;
}