using namespace std;

#include <iostream>

typedef long long int ll;

int main()
{
	ll N, r;
	cin >> N >> r;

	for(ll i=0; i<N; i++)
	{
		ll num;
		cin >> num;

		if(num>=r)
		{
			cout << "Good boi" << endl;
		}

		else
		{
			cout << "Bad boi" << endl;
		}
	}
	
	return 0;
}