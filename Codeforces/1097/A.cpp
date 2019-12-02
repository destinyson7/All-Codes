#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	string s;
	cin >> s;

	string a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	if(a[0]==s[0] || a[1]==s[1])
	{
		cout << "YES" << endl;
		return 0;
	}

if(b[0]==s[0] || b[1]==s[1])
	{
		cout << "YES" << endl;
		return 0;
	}

if(c[0]==s[0] || c[1]==s[1])
	{
		cout << "YES" << endl;
		return 0;
	}

	if(d[0]==s[0] || d[1]==s[1])
	{
		cout << "YES" << endl;
		return 0;
	}

	if(e[0]==s[0] || e[1]==s[1])
	{
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;
	return 0;
}