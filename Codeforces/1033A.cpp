using namespace std;

#include <iostream>

typedef long long int ll;

int main()
{
	ll n;
	cin >> n;

	ll ax, ay;
	cin >> ax >> ay;

	ll bx, by;
	cin >> bx >> by;

	ll cx, cy;
	cin >> cx >> cy;

	if(bx<ax && by<ay && cx<ax && cy<ay)
	{
		cout << "YES" << endl;
	}

	else if(bx<ax && by>ay && cx<ax && cy>ay)
	{
		cout << "YES" << endl;
	}

	else if(bx>ax && by<ay && cx>ax && cy<ay)
	{
		cout << "YES" << endl;
	}

	else if(bx>ax && by>ay && cx>ax && cy>ay)
	{
		cout << "YES" << endl;
	}

	else
	{
		cout << "NO" << endl;
	}

	return 0;
}