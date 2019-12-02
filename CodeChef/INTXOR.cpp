using namespace std;

#include <iostream>

typedef long long int ll;

ll a[50005];

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll N;
		cin >> N;

		for(ll i=1; i<=N; i++)
		{
			cout << "1 " << i << " " << i << " " << i << endl;
			cout << flush;

			cin >> a[i];
		}

		cout << "2 ";
		for(ll j=1; j<=N; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		cout << flush;

		ll num;
		cin >> num;
	}

	return 0;
}