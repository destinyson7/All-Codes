#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll safe[105];

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll M, x, y;
		cin >> M >> x >> y;

		for(ll m=0; m<105; m++)
		{
			safe[m] = 0;
		}

		for(ll i=0; i<M; i++)
		{
			ll temp;
			cin >> temp;

			safe[temp]=-1;

			for(ll j=temp+1; j<= temp+x*y && j<=100; j++)
			{
				safe[j] = -1;
			}

			for(ll j=temp-1; j>0 && j>= temp-x*y; j--)
			{
				safe[j] = -1;
			}
		}

		ll cnt = 0;
		for(ll k=1; k<=100; k++)
		{
			if(safe[k]==0)
			{
				cnt++;
			}
		}

		cout << cnt << endl;
	}


	return 0;
}