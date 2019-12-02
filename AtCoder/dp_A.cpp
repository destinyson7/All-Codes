#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll h[100005];
ll mini[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N;
	cin >> N;

	for(ll i=0; i<N; i++)
	{
		cin >> h[i];
	}

	mini[0] = h[0];
	mini[1] = abs(h[1]-h[0]);
	mini[2] = min(mini[1]+abs(h[2]-h[1]), abs(h[2]-h[0]));

	for(ll j=3; j<N; j++)
	{
		mini[j] = min(mini[j-1]+abs(h[j]-h[j-1]), mini[j-2]+abs(h[j]-h[j-2]));
	}

	cout << mini[N-1] << endl;

	return 0;
}