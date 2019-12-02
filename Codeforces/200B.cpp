#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin >> n;

	float sum = 0;

	ll temp;
	for(ll i=1; i<=n; i++)
	{
		cin >> temp;

		sum+=temp;
	}

	cout << fixed << setprecision(6) << sum/n << endl;

	return 0;
}