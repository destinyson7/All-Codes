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
	
	ll x, y, z;
	cin >> x >> y >> z;

	ll a, b, c;
	cin >> a >> b >> c;

	// a-=x;

	if(a < x)
	{
		// cout << "!" << endl;
		cout << "NO" << endl;
		return 0;
	}

	a-=x;
	// cout << a << " " << b << endl;
	if(a+b < y)
	{
		// cout << a+b << " " << y << endl;
		// cout << "!" << endl;
		cout << "NO" << endl;
		return 0;
	}

	// a-=x;
	a-=y;

	if(z > a+b+c)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;



	return 0;
}