using namespace std;

#include <iostream>

typedef long long int ll;

int main()
{
	ll n, k;
	cin >> n >> k;

	ll ans = 0;

	ll time = 240 - k;

	for(ll i=1; i<=n; i++)
	{
		time-=(5*i);

		if(time < 0)
		{
			break;
		}

		ans++;
	}

	cout << ans << endl;

	return 0;
}