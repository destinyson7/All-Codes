using namespace std;

#include <iostream>

typedef long long int ll;

int main()
{
	ll n, m;
	cin >> n >> m;

	for(ll i=1; i<=n; i++)
	{
		if(i%2==1)
		{
			for(ll j=1; j<=m; j++)
			{
				cout << "#";
			}

			cout << endl;
		}

		else
		{
			if(i%4==0)
			{
				cout << "#";

				for(ll j=1; j<m; j++)
				{
					cout << ".";
				}

				cout << endl;
			}

			else
			{
				for(ll j=1; j<m; j++)
				{
					cout << ".";
				}

				cout << "#" << endl;
			}
		}
	}
	
	return 0;
}