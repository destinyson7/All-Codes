using namespace std;

#include <iostream>

typedef long long int ll;

ll a[100005];

int main()
{
	ll K, P;
	cin >> K >> P;

	ll cnt=0;
	while(P)
	{
		a[cnt++]=P%K;
		P/=K;
	}

	if(cnt)
	{
		cout << "1 " << endl;
		cout << cnt-1 << endl;
		for(ll i=0; i<cnt; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}

	else
	{
		cout << "0" << endl;
	}

	return 0;
}