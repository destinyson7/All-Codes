using namespace std;

#include <iostream>

typedef long long int ll;

int main()
{
	string s;
	cin >> s;

	ll len = s.length();
	
	char max = 'a';

	for(ll i=0; i<len; i++)
	{
		if(s[i]>max)
		{
			max=s[i];
		}
	}

	ll cnt=0;
	for(ll j=0; j<len; j++)
	{
		if(s[j]==max)
		{
			cnt++;
		}
	}

	for(ll k=0; k<cnt; k++)
	{
		cout << max;
	}

	cout << endl;

	return 0;
}