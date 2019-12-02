#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

ll modexp(ll a, ll b, ll c)
{
    ll ans = 1;
    a%=c;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b>>=1;
    }

    return ans;
}

const ll L = 1e5+5;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;

    ll n = 0;

    n = s[1]-48 + 10*(s[3]-48) + 100*(s[4]-48) + 1000*(s[2]-48) + 10000*(s[0]-48);

    ll t = modexp(n, 5, 100000);

    printf("%05lld\n", t);

    return 0;
}