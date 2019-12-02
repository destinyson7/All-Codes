#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector <ll> resl[500005];
vector <ll> resh(500005);
vector <ll> resa(500005);

int main()
{
	ll n;
	cin >> n;

	string str;
	ll ans = 0;
	for(ll i=0; i<n; i++)
	{
		cin >> str;

		ll low = 0;
		ll len = str.length();
		ll useful = 1;
		for(ll j=0; j<len; j++)
		{
			// cout << "str[j] " << str[j] << " ";

			if(low && str[j]==')')
			{
				low--;
			}

			else if(str[j]=='(')
			{
				low++;
			}

			else
			{
				useful = 0;
				break;
			}

			// cout << low << " ";
		}
		// cout << endl;

		if(useful==1)
		{
			resl[low].push_back(i);
		}

		sort(resl[i].begin(), resl[i].end());
		resl[i].erase(unique(resl[i].begin(), resl[i].end()), resl[i].end());

		ll len2 = str.length();
		ll high = 0, useful2 = 1;
		for(ll k=len2-1; k>=0; k--)
		{
			// cout << "str[k] at " << str[k] << "at k = " << k << " ";

			if(high && str[k]=='(')
			{
				high--;
			}

			else if(str[k]==')')
			{
				high++;
			}

			else
			{
				useful2 = 0;
				break;
			}

			// cout << high << " ";
		}
		// cout << endl;

		if(useful2==1)
		{
			if(!high)
			{
				ans++;
			}

			else
			{
				resa[i] = 1;
				resh[i] = high;
			}
		}
	}

	ll fin = ans/2;

	for(ll p=0; p<n; p++)
	{
		if(resa[p])
		{
			ll high2 = resh[p];

			ll len3 = resl[high2].size();
			if(len3)
			{
				resl[high2].erase(resl[high2].begin());
				fin++;
			}
		}
	}

	cout << fin << endl;

	return 0;
}