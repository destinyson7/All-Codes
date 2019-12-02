#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

vector <string> s(255);
vector < pair <ll, ll> > store;

ll ans[255][255];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll T;
	cin >> T;

	for(ll k=1; k<=T; k++)
	{
		ll R, C;
		cin >> R >> C;

		for(ll i=0; i<R; i++)
		{
			// string s;
			cin >> s[i];
		}

		// cout << s[4][4] << " woah" << endl;

		for(ll i=0; i<R; i++)
		{
			// cout << "string is " << s[i] << endl;

			for(ll j=0; j<C; j++)
			{
				// cout << s[i][j];
				if(s[i][j]=='1')
				{
					ans[i][j] = 0;
				}

				else
				{
					// cout << s[i][j] << endl;
					// if(i==4 && j==4)
					// {
					// 	cout << "NP" << endl;
					// }

					ans[i][j] = 1e17;
					store.pb(mp(i, j));
				}
			}
			// cout << endl;
		}

		ll final = 1e17;

		for(ll i=0; i<(ll)store.size(); i++)
		{
			s[store[i].ff][store[i].ss] = '1';
			ans[store[i].ff][store[i].ss] = 0;

			ll maxi = 0;
			for(ll a=0; a<R; a++)
			{
				for(ll b=0; b<C; b++)
				{
					if(s[a][b]=='0')
					{
						for(ll p=0; p<R; p++)
						{
							for(ll q=0; q<C; q++)
							{
								if(s[p][q]=='1')
								{
									ans[a][b] = min(ans[a][b], abs(p-a) + abs(q-b));
								}
							}
						}

						maxi = max(maxi, ans[a][b]);
					}

					else
					{
						ans[a][b] = 0;
					}
				}
			}

			// cout << "maxi " << maxi << " at " << store[i].ff << " and " << store[i].ss << endl;

			final = min(final, maxi);

			s[store[i].ff][store[i].ss] = '0';

			for(ll a=0; a<R; a++)
			{
				for(ll b=0; b<C; b++)
				{
					ans[a][b] = 1e17;
				}
			}
		}

		if(store.size()==0)
		{
			final = 0;
		}

		store.clear();

		cout << "Case #" << k << ": " << final << endl;
	}

	return 0;
}