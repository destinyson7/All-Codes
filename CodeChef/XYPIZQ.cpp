#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	ll T;
	cin >> T;

	while(T--)
	{
		ll N, t, x, y, z;
		cin >> N >> t >> x >> y >> z;

		ll div = 2*N + 1;

		if(y==0)
		{
			cout << "1" << " " << div << endl;
		}

		else
		{
			ll hcf = 1;

			if(t==1)
			{
				if(y>x)
				{
					if(z==x)
					{
						ll num = y-1;
						ll den = 2*N+1;

						hcf = __gcd(num, den);

						num/=hcf;
						den/=hcf;

						cout << num << " " << den << endl;
					}

					else
					{
						ll num = 2*N - y;
						ll den = 2*N + 1;

						hcf = __gcd(num, den);

						num/=hcf;
						den/=hcf;

						cout << num << " " << den << endl;
					}
				}

				else
				{
					if(x==z)
					{
						ll num = y+1;
						ll den = 2*N+1;

						hcf = __gcd(num, den);

						num/=hcf;
						den/=hcf;

						cout << num << " " << den << endl;
					}

					else
					{
						ll num = 2*N + 2 - y;
						ll den = 2*N + 1;

						hcf = __gcd(num, den);

						num/=hcf;
						den/=hcf;

						cout << num << " " << den << endl;
					}
				}
			}

			else if(t==2 || t==4)
			{
				ll num = 2*N + 1 - 2*y;
				ll den = 2*N + 1;

				hcf = __gcd(num, den);

				num/=hcf;
				den/=hcf;

				cout << num << " " << den << endl;	

			}

			else if(t==3)
			{
				if(x==z)
				{
					if(y>z)
					{
						ll num = y-1;
						ll den = 2*N + 1;

						hcf = __gcd(num, den);

						num/=hcf;
						den/=hcf;

						cout << num << " " << den << endl;
					}

					else
					{
						ll num = y+1;
						ll den = 2*N + 1;

						hcf = __gcd(num, den);

						num/=hcf;
						den/=hcf;

						cout << num << " " << den << endl;	
					}
				}

				else
				{
					if(y>z)
					{
						ll num = 2*N - y;
						ll den = 2*N + 1;

						hcf = __gcd(num, den);

						num/=hcf;
						den/=hcf;

						cout << num << " " << den << endl;	
					}

					else
					{
						ll num = 2*N + 2 - y;
						ll den = 2*N + 1;

						hcf = __gcd(num, den);

						num/=hcf;
						den/=hcf;

						cout << num << " " << den << endl;	
					}
				}				
			}
		}	
	}	

	return 0;
}