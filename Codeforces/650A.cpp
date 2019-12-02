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

map <ll, ll> m1;
map <ll, ll> m2;
map <pll, ll> m3;

// set <pll> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    // ll rep = 1;

    for(ll i=0; i<n; i++)
    {
        ll x, y;
        cin >> x >> y;

        m1[x]++;
        m2[y]++;

        m3[mp(x, y)]++;
    }

    ll ans = 0;

    for(auto i: m1)
    {
        ans+=((i.ss*(i.ss-1))/2);
    }

    // cout << ans << endl;

    for(auto i: m2)
    {
        ans+=((i.ss*(i.ss-1))/2);
    }

    // cout << ans << endl;

    for(auto i: m3)
    {
        ans-=((i.ss*(i.ss-1))/2);
    }

    cout << ans << endl;

    return 0;
}