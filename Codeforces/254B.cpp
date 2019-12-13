#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) 
{
    os << "{ ";
    for(auto& y : x) 
    {
        os << y << " ";
    }
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) 
{
    return os << "[" << p.ff << ", " << p.ss << "]";
}

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
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b >>= 1;
    }

    return ans;
}

const ll L = 1e5+5;

vector <ll> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll pref[15];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;

    for(ll i=1; i<15; i++)
    {
        pref[i] = days[i] + pref[i-1];
    }

    vector <pair<pll, ll>> v;

    for(ll i=0; i<n; i++)
    {
        ll m, d, p, t;
        cin >> m >> d >> p >> t;

        ll start = pref[m-1] + d-t;
        ll end = pref[m-1] + d-1;

        v.pb(mp(mp(start, 0), p));
        v.pb(mp(mp(end, 1), p));
    }

    sort(all(v));

    ll req = 0;
    ll ans = 0;

    for(ll i=0; i<2*n; i++)
    {
        if(v[i].ff.ss == 0)
        {
            req += v[i].ss;
        }

        else
        {
            req -= v[i].ss;
        }

        ans = max(ans, req);
    }

    cout << ans << endl;

    return 0;
}