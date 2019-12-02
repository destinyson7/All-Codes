using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long int ll;

ll num[50005];
ll a[50005];

int main()
{
	ll T;
	cin >> T;

	while(T--)
	{
		ll N;
		cin >> N;

		if(N%4==0)
		{
			ll ans = 0;

			cout << "1 " << "1" << " " << "2" << " " << "3" << endl;
			cout << flush;
				
			cin >> num[1];
			ans^=num[1];
			
			cout << "1 " << "1" << " " << "2" << " " << "4" << endl;
			cout << flush;
				
			cin >> num[2];
			ans^=num[2];

			cout << "1 " << "1" << " " << "3" << " " << "4" << endl;
			cout << flush;
				
			cin >> num[3];
			ans^=num[3];

			a[1]=ans;

			cout << "1 " << "2" << " " << "3" << " " << "4" << endl;
			cout << flush;
				
			cin >> num[4];

			a[4] = a[1]^num[1]^num[4];
			a[3] = a[1]^a[4]^num[3];
			a[2] = a[1]^a[4]^num[2];
		}

		else if(N%4==1)
		{
			ll ans = 0;

			cout << "1 " << "1" << " " << "2" << " " << "3" << endl;
			cout << flush;
				
			cin >> num[1];
			ans^=num[1];
			
			cout << "1 " << "2" << " " << "3" << " " << "4" << endl;
			cout << flush;
				
			cin >> num[2];
			ans^=num[2];

			cout << "1 " << "3" << " " << "4" << " " << "5" << endl;
			cout << flush;
				
			cin >> num[3];
			ans^=num[3];

			cout << "1 " << "4" << " " << "5" << " " << "1" << endl;
			cout << flush;
				
			cin >> num[4];
			ans^=num[4];

			a[2]=ans^num[2];
			a[5]=ans^num[3];

			cout << "1 " << "2" << " " << "5" << " " << "1" << endl;
			cout << flush;
				
			cin >> num[5];

			a[1] = num[5]^a[2]^a[5];
			a[3] = num[1]^a[1]^a[2];
			a[4] = num[3]^a[3]^a[5];		
		}

		else if(N%4==2)
		{
			ll ans = 0;

			cout << "1 " << "1" << " " << "2" << " " << "3" << endl;
			cout << flush;
				
			cin >> num[1];
			ans^=num[1];
			
			cout << "1 " << "2" << " " << "3" << " " << "4" << endl;
			cout << flush;
				
			cin >> num[2];
			ans^=num[2];

			cout << "1 " << "1" << " " << "4" << " " << "5" << endl;
			cout << flush;

			cin >> num[3];
			ans^=num[3];

			cout << "1 " << "5" << " " << "6" << " " << "2" << endl;
			cout << flush;
			cin >> num[4];

			cout << "1 " << "3" << " " << "5" << " " << "6" << endl;
			cout << flush;
			cin >> num[5];

			cout << "1 " << "6" << " " << "1" << " " << "4" << endl;
			cout << flush;
			cin >> num[6];

			a[5] = num[1]^num[2]^num[3];
			a[4] = num[5]^num[4]^num[2];
			a[6] = num[3]^num[6]^a[5];
			a[3] = num[5]^a[5]^a[6];
			a[2] = num[2]^a[3]^a[4];
			a[1] = num[1]^a[2]^a[3];
		}

		else if(N%4==3)
		{
			cout << "1 " << "1" << " " << "2" << " " << "3" << endl;
			cout << flush;
			cin >> num[1];

			cout << "1 " << "2" << " " << "3" << " " << "4" << endl;
			cout << flush;
			cin >> num[2];

			cout << "1 " << "3" << " " << "4" << " " << "5" << endl;
			cout << flush;
			cin >> num[3];

			cout << "1 " << "5" << " " << "6" << " " << "4" << endl;
			cout << flush;
			cin >> num[4];

			cout << "1 " << "1" << " " << "6" << " " << "7" << endl;
			cout << flush;
			cin >> num[5];

			cout << "1 " << "7" << " " << "6" << " " << "2" << endl;
			cout << flush;
			cin >> num[6];

			cout << "1 " << "7" << " " << "5" << " " << "1" << endl;
			cout << flush;
			cin >> num[7];

			a[3] = num[5]^num[6]^num[1];
			a[4] = num[7]^num[5]^num[4];
			a[5] = num[3]^a[3]^a[4];
			a[6] = num[4]^a[4]^a[5];
			a[2] = num[2]^a[3]^a[4];
			a[1] = num[1]^a[2]^a[3];
			a[7] = num[7]^a[5]^a[1];
		}
		
		for(ll i=(5+N%4); i<=N; i+=4)
		{
			ll ans = 0;

			cout << "1 " << i << " " << i+1 << " " << i+2 << endl;
			cout << flush;

			cin >> num[i];
			ans^=num[i];

			cout << "1 " << i << " " << i+1 << " " << i+3 << endl;
			cout << flush;

			cin >> num[i+1];
			ans^=num[i+1];

			cout << "1 " << i << " " << i+2 << " " << i+3 << endl;
			cout << flush;

			cin >> num[i+2];
			ans^=num[i+2];

			a[i]=ans;

			cout << "1 " << i+1 << " " << i+2 << " " << i+3 << endl;
			cout << flush;

			cin >> num[i+3];
			a[i+3] = a[i]^num[i]^num[i+3];
			a[i+2] = a[i]^a[i+3]^num[i+2];
			a[i+1] = a[i]^a[i+3]^num[i+1];
		}	


		cout << "2 ";
		for(ll i=1; i<=N; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		cout << flush;

		ll read;
		cin >> read;		
	}

	return 0;
}