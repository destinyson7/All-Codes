#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// ll store1[500005];
// ll store2[500005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;

	ll maxi1 = 0;
	ll maxi2 = 0;
	// ll cnt = 0;

	for(ll k=0; k<n; k++)
	{
		char s;
		ll a, b;

		cin >> s;

		if(s=='+')
		{
			cin >> a >> b;

			if(a<b)
			{
				if(maxi2 < b)
				{
					maxi2 = b;
				}

				if(maxi1 < a)
				{
					maxi1 = a;
				}				
			}

			if(a>b)
			{
				if(maxi2 < a)
				{
					maxi2 = a;
				}

				if(maxi1 < b)
				{
					maxi1 = b;
				}
			}
		}

		else
		{
			cin >> a >> b;

			ll check1, check2;
			if(a>b)
			{
				check1 = a;
				check2 = b;
			}

			else
			{
				check1 = b;
				check2 = a;
			}

			if(check1<maxi2 || check2<maxi1)
			{
				cout << "NO" << endl;
			}

			else
			{
				cout << "YES" << endl;
			}
		}
	}

	return 0;
}