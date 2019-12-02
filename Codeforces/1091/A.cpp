#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll y, b, r;
	cin >> y >> b >> r;

	ll ans = 0;
	
	if(b>y && r>b)
	{
		ans = y+y+1+y+2;
	}

	else if(b>y && r<=b)
	{
		ans = r+ r-1 + r-2;
	}

	else if(b<=y && r>b)
	{
		ans = b+b-1+b+1;
	}

	else
	{
		ans = r+r-1+r-2;
	}

	cout << ans << endl;

	return 0;
}