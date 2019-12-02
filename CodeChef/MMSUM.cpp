#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll start[100005];
ll endi[100005];
ll arr[100005];

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll N;
		cin >> N;

		for(ll i=0; i<N; i++)
		{
			cin >> arr[i];
		}

		ll tempmax = arr[0];
		ll finalmax = arr[0];
		endi[0] = finalmax;

		for(ll j=1; j<N; j++)
		{
			tempmax+=arr[j];

			tempmax = max(tempmax, arr[j]);
			finalmax = max(finalmax, tempmax);

			endi[j] = tempmax;
		}	

		ll maxsum = finalmax;

		tempmax=arr[N-1];
		finalmax=arr[N-1];
		start[N-1]=finalmax;

		for(ll k=N-2; k>=0; k--)
		{
			tempmax+=arr[k];

			tempmax=max(tempmax, arr[k]);
			finalmax=max(finalmax, tempmax);

			start[k]=tempmax;
		}

		ll ans = maxsum;
		// cout << ans << endl;

		for(ll m=1; m<N-1; m++)
		{
			// cout << start[m+1] << " " << endi[m-1] << " for m= " << m << endl;
			ans = max(ans, start[m+1]+endi[m-1]);
		}

		cout << ans << endl;
	}

	return 0;
}