using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>

typedef long long int ll;

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll N;
		cin >> N;

		ll flag[105];

		for(ll m=0; m<105; m++)
		{
			flag[m]=0;
		}

		ll finalans=0;

		ll tem = N;
		ll ques=0;

		ll store[10];
		ll ask[10];

		if(N%2==0)
		{
			while(tem>6)
			{
				ll cnt=0;
				for(ll i=1; i<=N; i++)
				{
					if(flag[i]==0)
					{
						store[cnt++]=i;

						if(cnt==5)
						{
							cnt=0;
							break;
						}
					}
				}

				cout << "? " << store[0] << " " << store[1] << " " << store[2] << " " << store[3] << " " << store[4] << endl;
				cout << flush;

				ll a, b;
				cin >> a >> b;
				flag[a]=1;
				flag[b]=1;

				tem-=2;
			}

			for(ll j=1; j<=N; j++)
			{
				if(flag[j]==0)
				{
					ask[ques++]=j;
				}
			}
		}

		else
		{
			while(tem>5)
			{
				ll cnt=0;
				for(ll i=1; i<=N; i++)
				{
					if(flag[i]==0)
					{
						store[cnt++]=i;

						if(cnt==5)
						{
							cnt=0;
							break;
						}
					}
				}

				cout << "? " << store[0] << " " << store[1] << " " << store[2] << " " << store[3] << " " << store[4] << endl;
				cout << flush;

				ll a, b;
				cin >> a >> b;
				flag[a]=1;
				flag[b]=1;

				tem-=2;
			}

			for(ll j=1; j<=N; j++)
			{
				if(flag[j]==0)
				{
					ask[ques++]=j;
				}
			}

			for(ll k=1; k<=N; k++)
			{
				if(flag[k]==1)
				{
					ask[ques++]=k;
					break;
				}
			}
		}

		// for(ll c=0; c<6; c++)
		// {
		// 	cout << ask[c] << " ";
		// }
		// cout << endl;

		ll num1, num2;

		cout << "? " << ask[0] << " " << ask[1] << " " << ask[2] << " " << ask[3] << " " << ask[4] << endl;
		cout << flush;
		cin >> num1 >> num2;

		deque <ll> temp;
		temp.push_back(num1);
		temp.push_back(num2);

		for(ll i=0; i<6; i++)
		{
			if(ask[i]!=num1 && ask[i]!=num2)
			{
				temp.push_back(ask[i]);
			}
		}

		ll num3, num4;
		cout << "? " << temp[1] << " " << temp[2] << " " << temp[3] << " " << temp[4] << " " << temp[5] << endl;
		cout << flush;
		cin >> num3 >> num4;

		if(num3==temp[5])
		{
			// cout << "first if" << endl;
			ll num5, num6;
			cout << "? " << temp[1] << " " << temp[2] << " " << temp[3] << " " << temp[0] << " " << temp[5] << endl;
			cout << flush;
			cin >> num5 >> num6;

			if(num6==temp[1])
			{
				ll num7, num8;
				cout << "? " << temp[1] << " " << temp[2] << " " << temp[4] << " " << temp[0] << " " << temp[5] << endl;
				cout << flush;
				cin >> num7 >> num8;

				if(num8==temp[1])
				{
					finalans = temp[2];
				}

				else
				{
					finalans = temp[3];
				}
			}

			else
			{
				finalans = temp[4];
			}
		}

		else if(num3==temp[1])
		{
			// cout << "second if" << endl;
			if(num4==temp[5])
			{
				ll num5, num6;
				cout << "? " << temp[1] << " " << temp[2] << " " << temp[3] << " " << temp[0] << " " << temp[5] << endl;
				cout << flush;
				cin >> num5 >> num6;

				if(num6==temp[1])
				{
					finalans = temp[4];
				}

				else
				{
					ll num7, num8;
					cout << "? " << temp[1] << " " << temp[2] << " " << temp[4] << " " << temp[0] << " " << temp[5] << endl;
					cout << flush;
					cin >> num7 >> num8;

					if(num8==temp[5])
					{
						finalans = temp[2];
					}

					else
					{
						finalans = temp[3];
					}

				}
			}

			else
			{
				finalans = temp[5];
			}
		}

		else
		{
			// cout << "third if" << endl;
			deque <ll> value;
			for(ll q=0; q<6; q++)
			{
				if(ask[q]!=num1 && ask[q]!=num2 && ask[q]!=temp[5] && ask[q]!=num3)
				{
					value.push_back(ask[q]);
				}
			}

			ll num5, num6;
			cout << "? " << temp[1] << " " << num3 << " " << value[0] << " " << temp[0] << " " << temp[5] << endl;
			cout << flush;
			cin >> num5 >> num6;

			if(num6==temp[1])
			{
				finalans = value[0];
			}

			else
			{
				finalans = value[1];
			}
		}

		cout << "! " << finalans << endl;
	}

	return 0;
}