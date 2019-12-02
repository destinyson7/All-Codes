using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

typedef long long int ll;

int main()
{
	ll t;
	cin >> t;

	while(t--)
	{
		ll x;
		cin >> x;

		if(x%2==0)
		{
			cout << x/2 << endl;
		}

		else
		{
			cout << (x-3)/2 + 1 << endl;
		}
	}

	return 0;
}