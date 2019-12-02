using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long int ll;

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll n;
		cin >> n;

		cout << (n*n + n)*(3*n*n - n - 2)/12 << endl;
	}

	return 0;
}