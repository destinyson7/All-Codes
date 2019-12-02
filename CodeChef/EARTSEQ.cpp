#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll isPrime[700000];
ll primes[700000];
ll ans[50005];

void Sieve()
{
	isPrime[0]=1;
	isPrime[1]=1;

	for(ll i=2; i<700000; i++)
	{
		if(isPrime[i]==0)
		{
			for(ll j=2*i; j<700000; j+=i)
			{
				isPrime[j]=1;
			}
		}
	}
}

void storePrimes()
{
	ll cnt = 0;
	for(ll i=2; i<700000; i++)
	{
		if(isPrime[i]==0)
		{
			primes[cnt++]=i;
		}
	}

	// return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll T;
	cin >> T;

	Sieve();
	storePrimes();
	// ll noOfPrimes = storePrimes();
	// cout << noOfPrimes << endl;

	while(T--)
	{
		ll N;
		cin >> N;

		ll cnt1 = 0;

		for(ll i=0; i<N; i+=2)
		{
			ans[i]=primes[cnt1]*primes[cnt1+1];
			cnt1+=2;
		}

		ll cnt2=1;

		for(ll j=1; j<N; j+=2)
		{
			ans[j]=primes[cnt2]*primes[cnt2+1];
			cnt2+=2;
		}

		if(N%2==0)
		{
			ans[N-1] = primes[0]*primes[cnt1-1];
		}

		else
		{
			ans[N-1] = primes[cnt2-1]*primes[0];
		}

		for(ll k=0; k<N; k++)
		{
			cout << ans[k] << " ";
		}
		cout << endl;
	
		// for(ll i=0; i<N; i++)
		// {
		// 	cout << __gcd(ans[i%N], ans[(i+1)%N]) << " ";
		// 	cout << __gcd(__gcd(ans[i%N], ans[(i+1)%N]), ans[(i+2)%N]) << endl;
		// }

	}

	return 0;
}