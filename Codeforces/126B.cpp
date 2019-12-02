#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define endl "\n"

ll modmul(ll a, ll b, ll mod)
{
	ll ans = 0;
	a%=mod;

	while(b)
	{
		if(b&1)
		{
			ans = (ans+a)%mod;
		}

		a = (a+a)%mod;
		b>>=1;
	}

	return ans;
}

ll modexp(ll a, ll b, ll mod)
{
	ll ans = 1;
	a%=mod;

	while(b)
	{
		if(b&1)
		{
			ans = (ans*a)%mod; 
		}

		a = (a*a)%mod;
		b>>=1;
	}

	return ans;
}

map <ll, ll> ans;

bool verify(ll len, string s, ll start, ll stlen)
{
	for(ll i=0; i<len; i++)
	{
		if(s[i]!=s[start+i])
		{
			return false;
		}
	}

	return true;
}

bool check(ll len, string s, ll mod, ll stlen, ll p)
{
	if(len==0)
	{
		return true;
	}

	ll hash = 0;

	for(ll i=0; i<len; i++)
	{
		hash*=p;
		hash+=s[i];
		hash%=mod;
	}

	ll temp = modexp(p, len, mod);

	for(ll j=len; j<stlen-1; j++)
	{
		hash*=p;
		hash+=s[j];
		hash%=mod;
		hash-=temp*s[j-len];

		while(hash<0)
		{
			hash+=mod;
		}

		if(hash==ans[len])
		{
			// if(verify(len, s, j-len+1, stlen))
			// {
				return true;
			// }
		}
	}

	return false;
}

bool confirm(ll len, string s, ll stlen)
{
	for(ll i=0; i<len; i++)
	{
		if(s[i]!=s[stlen-len+i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin >> s;

	ll len = s.length();
	ll p = 31;

	ll hashpre = 0;
	ll hashsuff = 0;
	ll mod = 100000007;
	// ll temp = 1;

	for(ll i=0; i<len; i++)
	{
		hashpre*=p;
		hashpre+=s[i];
		hashpre%=mod;

		ll temp = modexp(p, i, mod);
		hashsuff+=modmul(temp, s[len-1-i], mod);
		hashsuff%=mod;

		// hashsuff += temp * s[len-1-i];
		// temp *= 97;
		// hashsuff %= mod;
		// temp %= mod;

		// cout << "pre: " << hashpre << " suff: " << hashsuff << endl;

		if(hashpre==hashsuff)
		{
			// if(confirm(i+1, s, len))
			// {
				ans[i+1] = hashpre;
			// }
		}
	}

	// cout << ans.size() << endl;

	if(ans.size()==0)
	{
		cout << "Just a legend" << endl;
		return 0;
	}

	vector <ll> v;

	for(auto it : ans)
	{
		v.pb(it.first);
	}

	ll start = 0;
	ll end = v.size()-1;

	ll store = 0;
	while(start<=end)
	{
		ll mid = start + (end-start)/2;

		if(check(v[mid], s, mod, len, p))
		{
			store = v[mid];
			start = mid+1;
		}

		else
		{
			end = mid-1;
		}
	}

	if(store==0)
	{
		cout << "Just a legend" << endl;
		return 0;
	}

	for(ll i=0; i<store; i++)
	{
		cout << s[i];
	}
	cout << endl;

	return 0;
}