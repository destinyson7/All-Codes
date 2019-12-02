#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll y, b, r;
	cin >> y >> b >> r;

	for(ll i=y; i; i--)
	{
		if(i<b && i+1<r)
		{
			cout << i+i+1+i+2 << endl;
			break;
		}
	}
	
	return 0;
}