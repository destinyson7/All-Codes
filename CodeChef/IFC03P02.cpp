#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll len1, len2;

ll lcs(string X, string Y, ll ite1, ll ite2)
{
	if(ite1==len1 || ite2==len2)
	{
		return 0;
	}

	if(X[ite1]==Y[ite2])
	{
		return 1+lcs(X, Y, ite1+1, ite2+1);
	}

	return max(lcs(X, Y, ite1+1, ite2), lcs(X, Y, ite1, ite2+1));
}

int main()
{
	string X;
	string Y;
	cin >> X >> Y;

	len1 = X.length();
	len2 = Y.length();

	ll ans = lcs(X, Y, 0, 0);

	cout << ans << endl;

	return 0;
}