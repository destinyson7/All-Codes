#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{	
	ll T;
	T = 25*49;
	cout << T << endl;

	for(ll i=1; i<=50; i++)
	{
		for(ll j=i; j<=50; j++)
		{
			if(i!=j)
			{
				cout << i << " " << j << endl;
			}
		}
	}

	return 0;
}