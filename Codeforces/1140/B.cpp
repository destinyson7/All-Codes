#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin >> t;

	while(t--)
	{
		ll n;
		cin >> n;

		string s;
		cin >> s;

		ll cnt1 = 0;
		ll cnt2 = 0;

		if(n<2 || s[0]=='>' || s[n-1]=='<')
		{
			cout << "0" << endl;
			continue;
		}

		else
		{
			for(ll i=0; i<n; i++)
			{
				if(s[i]=='<')
				{
					cnt1++;
				}

				else
				{
					break;
				}
			}

			for(ll i=n-1; i>=0; i--)
			{
				if(s[i]=='>')
				{
					cnt2++;
				}

				else
				{
					break;
				}
			}

			if(cnt1==0 || cnt2==0)
			{
				cout << "0" << endl;
			}

			else
			{
				cout << min(cnt1, cnt2) << endl;
			}
		}
	}

	return 0;
}