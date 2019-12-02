#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll arr[100005];
vector <ll> ans(100005);

void dp(ll arr[], ll N)
{
	ans[N-1] = 1;

	for(ll j=N-2; j>=0; j--)
	{
		if(arr[j]*arr[j+1]<0)
		{
			ans[j] = ans[j+1]+1;
		}

		else
		{
			ans[j] = 1;
		}
	}
}

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

		dp(arr, N);

		for(ll k=0; k<N; k++)
		{
			cout << ans[k] << " ";
			ans[k] = 0;
		}
		cout << endl;
	}

	return 0;
}