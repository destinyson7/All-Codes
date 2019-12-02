using namespace std;

#include <iostream>
#include <cmath>

typedef long long int ll;

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll N;
		cin >> N;

		ll sum=0, ans=2, a=2, b=1;
		for(ll i=0; sum<=N; i++)
		{
			sum=a+b;
			if(sum>N)
			{
				break;
			}
			
			b=a;
			a=sum;

			if(sum%2==0)
			{
				ans+=sum;
			}
		}

		cout << ans << endl;
	}

	return 0;
}