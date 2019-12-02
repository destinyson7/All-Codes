using namespace std;

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

typedef long long int ll;

int main()
{
	ll x;
	cin >> x;

	if(x==1)
	{
		cout << "-1" << endl;
	}

	else if(x==3)
	{
		cout << "2" << " " << "2" << endl;
	}
		
	else if(x==2)
	{
		cout << x << " " << x << endl;
	}
		
	else if(x==4)
	{
		cout << 4 << " " << 2 << endl;
	}
		
	else if(x&1)
	{
		cout << x-1 << " " << 2 << endl;
	}

	else
	{
		cout << x-2 << " " << 2 << endl;
	}

	return 0;
}