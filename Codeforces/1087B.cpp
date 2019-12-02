#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll n, k;
	cin >> n >> k;

	ll x = k;
	ll min = 1e15+7;
	for(ll i=1; i<k; i++)
	{
		x = (n*k)/i + i;
		// cout << "x: " << x << endl;

		// cout << x/k << " " << x%k << " " << (x/k)*(x%k) << endl;
		if((x/k)*(x%k)==n)
		{	
			if(x<min)
			{
				min = x;
				// cout << min << " at index " << i << endl;
			}
		}
	}

	cout << min << endl;
	
	return 0;
}