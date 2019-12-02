using namespace std;

#include <iostream>
#include <algorithm>

typedef long long int ll;

ll y[2005];

int main()
{
	ll n, k;
	cin >> n >> k;

	for(ll i=0; i<n; i++)
	{	
		cin >> y[i];
		y[i]=5-y[i];
	}

	sort(y, y+n);

	ll ans = 0;

	for(ll j=n-1; j>=0; j--)
	{
		// cout << " " << y[j];
		if((n-j)%3==0)
		{
			if(y[j]>=k)
				ans++;
		}
	}

	cout << ans << endl;
	
	return 0;
}