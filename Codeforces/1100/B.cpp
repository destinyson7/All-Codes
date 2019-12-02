#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

set <ll> check;
ll ans[100005];
ll flag[100005];
ll a[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, m;
	cin >> n >> m;



	for(ll i=0; i<m; i++)
	{
		cin >> a[i];

		flag[a[i]]++;
		check.insert(a[i]);

		if(check.size()==n)
		{
			ans[i] = 1;

			check.clear();

			for(ll j=1; j<=n; j++)
			{
				flag[j]--;

				if(flag[j]>0)
				{
					check.insert(j);
				}
			}
		}
	}	

	for(ll j=0; j<m; j++)
	{
		if(ans[j]==1)
		{
			cout << "1";
		}

		else
		{
			cout << "0";
		}
	}
	cout << endl;
	
	return 0;
}