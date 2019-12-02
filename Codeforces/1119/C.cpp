#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 505;

ll A[L][L];
ll B[L][L];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, m;
	cin >> n >> m;

	for(ll i=0; i<n; i++)
	{
		for(ll j=0; j<m; j++)
		{
			cin >> A[i][j];
		}
	}

	for(ll i=0; i<n; i++)
	{
		for(ll j=0; j<m; j++)
		{
			cin >> B[i][j];
		}
	}

	return 0;
}