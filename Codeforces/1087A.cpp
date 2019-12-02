#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	string t;
	cin >> t;

	ll len = t.length();

	ll start = (len-1)/2;
	ll end = start + 1;

	while(start>=0 || end<len)
	{	
		if(start>=0)
		{
			cout << t[start--];
		}

		if(end<len)
		{
			cout << t[end++];
		}
	}
	cout << endl;

	return 0;
}