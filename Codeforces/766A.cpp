using namespace std;

#include <iostream>

typedef long long int ll;

int main()
{
	string a, b;

	cin >> a;
	cin >> b;

	ll len1 = a.length();
	ll len2 = b.length();

	if(a==b)
	{
		cout << "-1" << endl;
	}

	else
	{
		cout << max(len1, len2) << endl;
	}

	return 0;
}