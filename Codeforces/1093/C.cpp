using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

typedef long long int ll;

ll b[200005];
ll a[200005];

int main()
{
	ll n;
	cin >> n;

	for(ll i=1; i<=n/2; i++)
	{
		cin >> b[i];
	}

	a[1] = 0;
	a[n] = b[1];

	for(ll k=2; k<=n/2; k++)
	{
		if(b[k] - b[k-1] > 0)
		{
			a[k] = b[k] - b[k-1] + a[k-1];
			a[n-k+1] = b[k] - a[k];
		}

		else
		{
			a[k] = a[k-1];
			a[n-k+1] = b[k] - a[k];
		}
	}

	for(ll j=1; j<=n; j++)
	{
		cout << a[j] << " ";
	}
	cout << endl;

	return 0;
}