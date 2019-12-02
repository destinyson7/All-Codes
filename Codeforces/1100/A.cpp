#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll a[105];
ll dont[105];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, k;
	cin >> n >> k;

	for(ll i=1; i<=n; i++)
	{
		cin >> a[i];
	}	

	ll ans = 0;
	for(ll j=1; j<=n; j++)
	{
		ll temp = j;

		while(temp > 0)
		{
			temp-=k;
		}

		if(temp<=0)
		{
			temp+=k;
		}

		for(ll an=temp; an<=n; an+=k)
		{
			dont[an] = -1;
		}

		ll cnt1=0, cnt2=0;
		for(ll c=1; c<=n; c++)
		{
			if(dont[c]!=-1)
			{
				if(a[c]==1)
				{
					cnt1++;
				}

				else
				{
					cnt2++;
				}
			}
		}

		ans = max(ans, abs(cnt1-cnt2));

		for(ll g=1; g<=n; g++)
		{
			dont[g]=0;
		}

	}

	cout << ans << endl;

	return 0;
}