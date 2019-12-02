#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll gcd(ll x, ll y)
{
	if(y==0)
	{
		return x;
	}

	return gcd(y, x%y);
}

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll ang;
		cin >> ang;

		if(ang < 90 || (360%(2*(180-ang)))!=0)
		{
			// cout << gcd(2*ang, 360) << endl;
			cout << 360/gcd(2*ang, 360) << endl;
		}

		else
		{
			cout << 720/gcd(2*(180-ang), 360) << endl;
		}
	}
	
	
	return 0;
}