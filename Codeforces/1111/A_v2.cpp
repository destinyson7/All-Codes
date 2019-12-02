#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s, t;
	cin >> s >> t;

	ll len1 = s.length();
	ll len2 = t.length();

	if(len1!=len2)
	{
		cout << "No" << endl;
		return 0;
	}

	for(ll i=0; i<len1; i++)
	{
		if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') && (t[i]!='a' && t[i]!='e' && t[i]!='i' && t[i]!='o' && t[i]!='u'))
		{
			cout << "No" << endl;
			return 0;
		}

		if((s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u') && (t[i]=='a' || t[i]=='e' || t[i]=='i' || t[i]=='o' || t[i]=='u'))
		{
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}