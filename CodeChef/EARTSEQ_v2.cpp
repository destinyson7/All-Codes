#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll isPrime[700000];
ll primes[700000];
ll ans[50010];

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

ll storePrimes()
{
	ll cnt = 0;
	for(ll i=2; i<700000; i++)
	{
		if(isPrime[i]==0)
		{
			primes[cnt++]=i;
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll T;
	cin >> T;

	Sieve();
	// storePrimes();
	ll noOfPrimes = storePrimes();
	// cout << noOfPrimes << endl;

	while(T--)
	{
		ll N;
		cin >> N;

		ll cnt1 = 6;

		ans[0]=55;
		for(ll i=1; i<N; i+=4)
		{
			ans[i]=5*primes[cnt1];
			ans[i+1]=7*primes[cnt1++];
			ans[i+2]=7*primes[cnt1];
			ans[i+3]=5*primes[cnt1++];
		}

		// ll cnt2=1;

		// for(ll j=1; j<N; j+=2)
		// {
		// 	ans[j]=primes[cnt2]*primes[cnt2+1];
		// 	cnt2+=2;
		// }

		ans[0]*=2;
		ans[N-1]*=2;
		// ans[N-1] = (ans[N-2]/__gcd(ans[N-2], ans[N-3]))*2;

		if((N-1)%4==1 || (N-1)%4==0)
		{
			if((N-1)%4==0)
			{
				ans[N-1]/=5;
			}	

			else
			{				
				ans[N-2]=((ans[N-3]*3)/__gcd(ans[N-3], ans[N-4]));
				ans[N-1]=((ans[N-2]*6)/__gcd(ans[N-2], ans[N-3]));
				
				// ans[N-2] = (ans[N-3]/__gcd(ans[N-4], ans[N-5]))*3;
				// for(ll m=1; m<50000; m++)
				// {
				// 	if(ans[N-1]%primes[m]==0 && ans[N-3]%primes[m]!=0)
				// 	{
				// 		ans[N-2]*=primes[m];
				// 		cout << "Multiplied: " << primes[m] << endl;
				// 		break;
				// 	}
				// }
				// cout << __gcd(ans[0], ans[N-1]) << endl;
			}
		}

		ll maxi = ans[0];
		for(ll k=0; k<N; k++)
		{
			cout << ans[k] << " ";

			maxi = max(maxi, ans[k]);

			// if(ans[k] > 1e9)
			// {
			// 	cout << "WRONG3 at N=" << N << " and value is " << ans[k] << endl;
			// }
		}
		cout << endl;

		// cout << "Maximum: " << maxi << endl;
	
		// for(ll i=0; i<N; i++)
		// {
		// 	if(__gcd(ans[i%N], ans[(i+1)%N]) == 1)
		// 	{
		// 		cout << "WRONG at " << N << " and gcd is " << __gcd(ans[i%N], ans[(i+1)%N]) << " at i=" << i << endl;
		// 		return 0;
		// 	}

		// 	if(__gcd(__gcd(ans[i%N], ans[(i+1)%N]), ans[(i+2)%N]) != 1)
		// 	{
		// 		cout << "WRONG2 at " << N << " and gcd is " << __gcd(__gcd(ans[i%N], ans[(i+1)%N]), ans[(i+2)%N]) << " at i= " << i << endl;
		// 		return 0;
		// 	}
		// }

	}

	return 0;
}