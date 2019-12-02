#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll a[1000005];
ll res[1000005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, k, m;
	cin >> n >> k >> m;

	ll sum = 0;
	for(ll i=0; i<n; i++)
	{
		cin >> a[i];
		sum+=a[i];
	}

	sort(a, a+n);

	ll temp = 0;

	double ans = 0;
	for(ll j=0; j<n; j++)
	{
		res[j] = sum - temp;
		temp+=a[j];

		ll temp2 = m - j;
		temp2-=((n-j)*k);
		temp2 = min((ll)0, temp2);
		res[j] += (n-j)*k + temp2;

		ans = max((double)res[j]/(double)(n - j), ans);
	}
	
	cout << fixed << setprecision(12) << ans << endl;

	return 0;
}