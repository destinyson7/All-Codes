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

		ll a, b, c;

		ll max = -1, flag=0;
		for(a=N; a>0; a--)
		{
			for(b=a-1; b>0; b--)
			{
				for(c=b-1; c>0; c--)
				{
					if(a+b+c==N)
					{
						// cout << a << " " << b << " " << c << endl;
						if(a*a == b*b + c*c)
						{
							max = a*b*c;
							flag=1;
						}

						break;
					}
				}

				if(flag==1)
				{
					break;
				}
			}

			if(flag==1)
			{
				break;
			}
		}

		cout << max << endl;
	}

	return 0;
}