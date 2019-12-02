#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, d;
	cin >> n >> d;

	string s;
	cin >> s;

	ll ans = 0;
	for(ll i=0; i<n;)
	{
		ll last = -1;
		for(ll j=i+1; j<n && j<=i+d; j++)
		{
			if(s[j]=='1')
			{
				last = j;
				// cout << "last= " << last << " at j= " << j << " and s[j]=" << s[j] << " and i=" << i << endl;
			}
		}

		if(last==-1)
		{
			cout << "-1" << endl;
			return 0;
		}

		i=last;

		// cout << "last " << last << "at i=" << i << endl;

		ans++;
	
		if(i==n-1)
		{
			break;
		}

	}

	cout << ans << endl;

	return 0;
}