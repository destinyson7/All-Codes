#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll primeFactorization(ll x, ll n)
{
		// cout << "x " << x << " and n= " << n << endl;	

	// ll b = x;
	ll ans = n;

	ll temp5 = 0;
	while(x%2==0)
	{
		temp5++;
		x/=2;
	}

	ll temp6 = n;
	if(temp5>0)
	{
		ll no = 0;
		while(temp6!=0)
		{
			temp6/=2;
			no+=temp6;
		}

		ans = min(ans, no/temp5);
	}

	// b = x;

	ll root = sqrt(x);
	ll temp = 0, temp3 = n, temp2 = 0;
	for(ll i=3; i<=root; i++)
	{
		// temp = n;
		temp = 0;

		if(x%i==0)
		{
			while(x%i==0)
			{
				temp++;
				x/=i;
			}

			temp2 = 0;
			temp3 = n;

			while(temp3/i > 0)
			{
				temp2+=temp3/i;
				temp3/=i;
			}

			ans = min(ans, temp2/temp);
			// cout << "ans " << ans << " at i=" << i << endl;
		}
	}

	// cout << "x " << x << " and n= " << n << endl;	
	if(x>2)
	{
		
		ll rrr = 0;
		while(n!=0)
		{
			n/=x;
			rrr+=n;

		}
		// cout << "Ans " << ans << endl;
		ans = min(ans, rrr);

	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, b;
	cin >> n >> b;

	ll ans = primeFactorization(b, n);

	cout << ans << endl;

	return 0;
}