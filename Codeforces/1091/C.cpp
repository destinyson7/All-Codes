#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector <ll> res;

ll gcd(ll a, ll b)
{
	if(b==0)
	{
		return a;
	}

	return gcd(b, a%b);
}

int main()
{
	ll n;
	cin >> n;

	for(ll i=1; i*i<=n; i++)
	{
		if(gcd(n, i)>1)
		{
			res.push_back((((n/gcd(n, i) - 1)*n)/2) + n/gcd(n, i));
		}

		if(!(n%i))
		{
			if(gcd(n, n/i)>1)
			{
				res.push_back((((n/gcd(n, n/i) - 1)*n)/2) + n/gcd(n, n/i));
			}
		}		
	}
	res.push_back(((n*(n+1))/2));

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());	
	
	for(ll j=0; j<res.size(); j++)
	{
		cout << res[j] << " ";
	}
	cout << endl;

	return 0;
}