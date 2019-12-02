using namespace std;

#include <iostream>

typedef long long int ll;

ll flag[150005];

int main()
{
	ll N, c;
	cin >> N >> c;

	ll mid = 1;

	ll low = 1;
	ll high = N;

	ll num=0;
	while(low<=high)
	{
		if(flag[mid]==1)
		{
			cout << "2" << endl; 
			cout << flush;
			cout << "3 " << mid << endl;
			cout << flush;
			break;
		}

		else if(num==1)
		{
			cout << "2 " << endl;
			cout << flush;
		}

		cout << "1 " << mid << endl;
		cout << flush;
		flag[mid]=1;

		cin >> num;

		if(num==1)
		{
			high = mid;
			// cout << "2 " << endl;	
			// cout << flush;
		}

		else if(num==0)
		{
			low = mid + 1;
		}

		mid = (high+low)/10;

		ll h=10;
		while(mid<low || mid>high)
		{
			mid = low + (high-low)/h--;
		}
	}

	return 0;
}