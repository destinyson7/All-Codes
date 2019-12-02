#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

vector <ll> a;
set <ll> l;

ll go[5205][5205];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;

	for(ll i=0; i<n; i++)
	{
		for(ll j=0; j<n; j+=4)
		{
			char c;
			cin >> c;

			ll temp = 0;
			if(c>'0' && c<'9')
			{
				temp = (ll)c - 48;
			}

			else
			{
				temp = (ll)c - 55;
			}	

			go[i][j+3] = temp%2;
			temp/=2;
			go[i][j+2] = temp%2;
			temp/=2;
			go[i][j+1] = temp%2;
			temp/=2;
			go[i][j] = temp%2;
			temp/=2;
		}
	}

	for(ll a=1; a<=n; a++)
	{
		if(n%a==0)
		{
			l.insert(a);
		}
	}

	for(auto it:l)
	{
		a.push_back(it);
	}

	ll left = 0;
	ll right = a.size();

	ll mid = left + (right-left)/2;

	ll check = -1e9;
	while(mid!=check)
	{
		check = mid;

		ll flag = 0;
		for(ll m=0; m<n; m++)
		{
			for(ll o=0; o<n; o++)
			{
				if(go[m][o]!=go[m/a[mid]*a[mid]][o/a[mid]*a[mid]])
				{
					flag = 1;
					break;
				}

			}

			if(flag==1)
			{
				break;
			}	
		}

		if(!flag)
		{
			left = mid;
		}

		else
		{
			right = mid;
		}

		mid = left + (right-left)/2;
	}

	ll ans = a[mid];

	cout << ans << endl;	

	return 0;
}