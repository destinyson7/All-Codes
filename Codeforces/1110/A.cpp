#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll modexp(ll a, ll b, ll c)
{
	ll ans=1;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans*a)%c);
		}

		b/=2;		
		a=(a*a)%c;
	}

	return ans;
}

ll modmul(ll a, ll b, ll c)
{
	ll ans=0;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans+a)%c);
		}

		b/=2;
		a=(a*2)%c;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll b, k;
	cin >> b >> k;

	ll a;
	ll ans = 0;

	for(ll i=1; i<=k; i++)
	{
		cin >> a;

		ll temp = modexp(b, k-i, 2);
		ans+=modmul(temp, a, 2);
	}

	if(ans&1)
	{
		cout << "odd" << endl;
	}

	else
	{
		cout << "even" << endl;
	}
	return 0;
}