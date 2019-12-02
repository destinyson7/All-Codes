#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll h[100005];
ll ans[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N, K;
	cin >> N >> K;

	for(ll i=0; i<N; i++)
	{
		cin >> h[i];
	}	

	for(ll i=1; i<N; i++)
	{
		ans[i] = ans[i-1] + abs(h[i]-h[i-1]);
		for(ll j=i-2; j>=0 && j>=i-K; j--)
		{
			ans[i] = min(ans[i], ans[j]+abs(h[i]-h[j]));
		}
	}

	cout << ans[N-1] << endl;

	return 0;
}