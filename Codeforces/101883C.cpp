#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		char s[1000005];

		scanf(" %[^\n]s", s);

		ll len = strlen(s);

		ll flag = 0;

		ll i=0;
		for(i=0; i<len; i++)
		{
			if(s[i]==' ')
			{
				flag = 1;
				break;
			}
		}

		if(flag==0)
		{
			if(len>1)
			{
				cout << (char)(s[1]-32);
			
				for(ll j=2; j<len; j++)
				{
					cout << s[j];
				}
				cout << (char)(s[0]+32) << "ay" << endl;
			}

			else
			{
				cout << s[0] << "ay" << endl;
			}
		}

		else
		{
			if(i>1)
			{
				cout << (char)(s[1]-32);
			
				for(ll j=2; j<i; j++)
				{
					cout << s[j];
				}
				cout << (char)(s[0]+32) << "ay" << " ";
			}

			else
			{
				cout << s[0] << "ay" << " ";
			}

			ll start=i+1, end;
			for(ll k=i+1; k<len; k++)
			{
				if(s[k]==' ')
				{
					end = k;
					
					if(end>start+1)
					{
						// cout << (char)(s[start+1]);
					
						for(ll j=start+1; j<end; j++)
						{
							cout << s[j];
						}
						cout << (char)(s[start]) << "ay" << " ";
					}

					else
					{
						cout << s[start] << "ay" << " ";
					}

					start = k+1;
				}
			}

			if(len>start+1)
			{
				// cout << (char)(s[start+1]);
				
				for(ll j=start+1; j<len; j++)
				{
					cout << s[j];
				}
				cout << (char)(s[start]) << "ay" << " ";
			}

			else
			{
				cout << s[start] << "ay" << " ";
			}

			cout << endl;
		}
	}

	return 0;
}