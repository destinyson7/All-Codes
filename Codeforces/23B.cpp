#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
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

		cout << max((ll)0, n-2) << endl;
	}	

	return 0;
}