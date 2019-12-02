using namespace std;

#include <iostream>

typedef long long int ll;

int main()
{
	ll n, m;
	cin >> n >> m;

	if(m>n && n!=0)
	{
		cout << "-1" << endl;
	}

	else
	{
		ll ans;
		ans = n/2 + n%2;

		for(ll i=0; ; i++)
		{
			if(i*m >= ans)
			{
				ans = i*m;
				break;
			}
		}

		cout << ans << endl;
	}

	return 0;
}