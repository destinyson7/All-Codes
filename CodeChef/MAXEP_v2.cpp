using namespace std;

#include <iostream>

typedef long long int ll;

int main()
{
	ll N, c;
	cin >> N >> c;

	ll ans = 1;

	while(ans<=N)
	{
		cout << "1 " << ans << endl;
		cout << flush;
	
		ll num;
		cin >> num;

		if(num==1)
		{
			cout << "2" << endl ;
			cout << flush;
			cout << "3 " << ans << endl;
			cout << flush;
			break;
		}

		else if(num==0)
		{
			ans++;
		}
	}

	return 0;
}