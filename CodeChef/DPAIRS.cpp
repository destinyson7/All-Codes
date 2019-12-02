#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll a[200005];
ll b[200005];

int main()
{
	ll N, M;
	cin >> N >> M;

	ll mini = 0, maxi = 0;

	for(ll i=0; i<N; i++)
	{
		cin >> a[i];

		if(a[i] < a[mini])
		{
			mini = i;
		}
	}

	for(ll j=0; j<M; j++)
	{
		cin >> b[j];

		if(b[j] > b[maxi])
		{
			maxi = j;
		}
	}

	for(ll k=0; k<M; k++)
	{
		cout << mini <<  " " << k << endl;
	}

	for(ll p=0; p<N; p++)
	{
		if(p!=mini)
		{
			cout << p << " " << maxi << endl;
		}
	}

	


	return 0;
}