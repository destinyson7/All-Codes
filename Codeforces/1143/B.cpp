#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

ll sumOfDigits(ll a) 
{ 
	ll sum = 1; 
	while (a) 
	{ 
		sum *= a % 10; 
		a /= 10; 
	} 
	return sum; 
} 

ll findMax(ll x) 
{ 
	ll b = 1, ans = x; 

	while (x) 
	{ 

		ll cur = (x - 1) * b + (b - 1); 

		if (sumOfDigits(cur) > sumOfDigits(ans) || 
		(sumOfDigits(cur) == sumOfDigits(ans) && 
			cur > ans)) 
			ans = cur; 

		x /= 10; 
		b *= 10; 
	} 

	return ans; 
} 


int main() 
{ 
	ll n;
	cin >> n;

	ll a = findMax(n);

	ll ans = 1;
	while(a)
	{
		ans*=(a%10);
		a/=10;
	}

	cout << ans << endl;

	return 0; 
} 
