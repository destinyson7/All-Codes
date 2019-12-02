#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

string s[505];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll R, C;
	cin >> R >> C;

	for(ll i=0; i<R; i++)
	{
		cin >> s[i];
		s[i][C] = '.';
		s[R][i] = '.';
	}


	for(ll i=0; i<R; i++)
	{
		for(ll j=0; j<C; j++)
		{
			if(s[i][j]=='S')
			{
				if(s[i][j+1]=='W' || s[i+1][j]=='W' || (j>0 && s[i][j-1]=='W') || (i>0 && s[i-1][j]=='W'))
				{
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}

	cout << "Yes" << endl;

	for(ll i=0; i<R; i++)
	{
		for(ll j=0; j<C; j++)
		{
			if(s[i][j]=='.')
			{
				cout << "D";
			}

			else
			{
				cout << s[i][j];
			}
		}
		cout << endl;
	}

	return 0;
}