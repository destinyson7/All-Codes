#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll a[100005];
ll cnt[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}

	for(ll j=1; j<=1e5; j++)
	{
		if(cnt[j]%2==1)
		{
			cout << "Conan" << endl;
			return 0;
		}
	}

	cout << "Agasa" << endl;

	return 0;
}