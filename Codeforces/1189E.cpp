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

const ll L = 1e5+5;

ll modexp(ll a, ll b, ll c)
{
    a%=c;
    ll ans = 1;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, p, k;
    cin >> n >> p >> k;

    map <ll, ll> m;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        ll t = modexp(a, 4, p);
        t-=((k*a)%p);
        t = (t+p)%p;

        m[t]++;
    }

    ll ans = 0;

    for(auto i: m)
    {
        ans+=((i.ss*(i.ss-1))/2);
    }

    cout << ans << endl;


    return 0;
}