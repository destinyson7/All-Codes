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
		ll N;
		cin >> N;

		ll ans = 0;

		ll num;

		cout << "1 " << "1" << " " << "2" << " " << "3" << endl;
		cout << flush;
			
		cin >> num;
		ans^=num;
		
		cout << "1 " << "1" << " " << "2" << " " << "4" << endl;
		cout << flush;
			
		cin >> num;
		ans^=num;

		cout << "1 " << "1" << " " << "3" << " " << "4" << endl;
		cout << flush;
			
		cin >> num;
		ans^=num;

		cout << "2 ";
		for(ll i=1; i<=N; i++)
		{
			cout << ans++ << " ";
		}
		cout << endl;
		cout << flush;

		ll read;
		cin >> read;
	}

	return 0;
}