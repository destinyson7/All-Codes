#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

const ll L = (1<<17)+5;

vector <ll> a(L);
vector <ll> seg(4*L);

ll make(ll i, ll tl, ll tr, ll f)
{
	if(tl==tr)
	{
		seg[i] = a[tl];

		// cout << seg[i] << " at i: " << i << endl;
		return seg[i];
	}

	ll mid = tl + (tr-tl)/2;

	ll left = make(i<<1, tl, mid, 1-f);
	ll right = make(i<<1|1, mid+1, tr, 1-f);

	if(f)
	{
		seg[i] = left|right;
	}

	else
	{
		seg[i] = left^right;
	}

	// cout << seg[i] << " at i: " << i << endl;
	return seg[i];
}

void update(ll i, ll tl, ll tr, ll idx, ll val, ll f)
{
	if(tl==tr)
	{
		seg[i] = val;
		return;
	}

	ll mid = tl + (tr-tl)/2;

	if(tl<=idx && idx<=mid)
	{
		update(i<<1, tl, mid, idx, val, 1-f);
	}

	else
	{
		update(i<<1|1, mid+1, tr, idx, val, 1-f);
	}

	if(f)
	{
		seg[i] = seg[i<<1]|seg[i<<1|1];
	}

	else
	{
		seg[i] = seg[i<<1]^seg[i<<1|1];
	}
}

void print(vector <ll> arr, ll N)
{
	for(ll i=1; i<=N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, m;	
	cin >> n >> m;

	for(ll i=1; i<=(1<<n); i++)
	{
		cin >> a[i];
	}

	// print(a, 1<<n);

	make(1, 1, 1<<n, n%2);

	// cout << seg[1] << endl;

	while(m--)
	{
		ll p, b;
		cin >> p >> b;

		update(1, 1, 1<<n, p, b, n%2);

		cout << seg[1] << endl;
	}


	return 0;
}