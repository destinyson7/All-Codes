#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e5+5;

vector <ll> a(L);
map <ll, ll> leftf;
map <ll, ll> rightf;
vector <ll> leftc(L);
vector <ll> rightc(L);

ll query(ll i, ll tl, ll tr, ll l, ll r)
{
	if(r<tl || l>tr)
	{
		return 0;
	}

	// if(tl<=l && )
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=1; i<=n; i++)
	{
		cin >> a[i];
	}

	for(ll i=1; i<=n; i++)
	{
		leftf[a[i]]++;
		leftc[i] = leftf[a[i]];
	}

	for(ll i=n; i>0; i--)
	{
		rightf[a[i]]++;
		rightc[i] = rightf[a[i]];
	}

	ll ans = 0;

	for(ll i=n; i>0; i--)
	{
		ans+=query(1, 1, n, 1, leftc[i]-1);
	}


	return 0;
}