using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

typedef long long int ll;

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll N, K;
		string s;

		cin >> N >> K;
		cin >> s;

		for(ll i=0; i<N; i++)
		{
			s[i]-=48;
		}

		ll max = 0;

		for(ll i=0; i<N-K+1; i++)
		{
			ll pr = 1;

			for(ll j=i; j<i+K; j++)
			{
				pr*=s[j];
			}

			if(pr > max)
			{
				max = pr;
			}
		}

		cout << max << endl;
	}

	return 0;
}