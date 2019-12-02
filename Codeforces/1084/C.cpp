using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

typedef long long int ll;

ll store[100005];

ll modmul(ll a,ll b,ll c)
{
	ll ans=0;

	a%=c;

	while(b)
	{
		if(b&1)
		{
			ans=((ans+a)%c);
		}
		b >>= 1;
		a=(a*2)%c;
	}

	return ans;
}

int main()
{
	string s;
	cin >> s;
	s.append("b");

	ll len = s.length();
	ll mod = 1000000007;
	ll cnta=0, cntb=0;
	ll flag=0;
	
	for(ll m=0; m<100005; m++)
	{
		store[m]=1;
	}

	for(ll i=0; i<len; i++)
	{
		if(s[i]=='a')
		{
			cnta++;
			flag=0;
		}

		if(s[i]=='b' && flag==0)
		{
			store[cntb++]=cnta+1;
			cnta=0;
			flag=1;
		}
	}	

	ll ans=1;
	for(ll j=0; j<cntb; j++)
	{
		ans = modmul(ans, store[j], mod);
	}

	ans--;
	ans+=mod;
	ans%=mod;

	cout << ans << endl;

	return 0;
}