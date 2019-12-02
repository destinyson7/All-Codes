#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

#define pi (double)3.141592653589793238462643

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, r;
	cin >> n >> r;

	double ans = sin(pi/n);

	double print = r/(1/ans - 1);

	cout << fixed << setprecision(9) << print << endl;
	
	return 0;
}