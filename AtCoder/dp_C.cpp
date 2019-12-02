#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll dp[100005][5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;

	ll a, b, c;
	for(ll i=0; i<n; i++)
	{
		cin >> a >> b >> c;

		if(i)
		{
			dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
			dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = c + max(dp[i-1][1], dp[i-1][0]);
		}

		else
		{
			dp[i][0]=a;
			dp[i][1]=b;
			dp[i][2]=c;
		}
	}

	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;

	return 0;
}