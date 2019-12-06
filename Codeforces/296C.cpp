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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    vector <pair<pll,ll>> queries;

    for(ll i=0; i<m; i++)
    {
        ll l, r, d;
        cin >> l >> r >> d;

        l--;
        r--;

        queries.pb(mp(mp(l, r), d));
    }

    vector <ll> cnt(m+5, 0);

    for(ll i=0; i<k; i++)
    {
        ll x, y;
        cin >> x >> y;

        x--;
        y--;

        cnt[x]++;

        cnt[y+1]--;
    }

    for(ll i=1; i<m; i++)
    {
        cnt[i] += cnt[i-1];
    }

    // for(ll i=0; i<m; i++)
    // {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;

    vector <ll> add(n+5, 0);

    for(ll i=0; i<m; i++)
    {
        ll l = queries[i].ff.ff;
        ll r = queries[i].ff.ss;
        ll d = queries[i].ss;

        // cout << l << " " << r << " " << d << endl;

        add[l] += cnt[i]*d;

        add[r+1] -= cnt[i]*d;
    }

    for(ll i=1; i<n; i++)
    {
        add[i] += add[i-1];
    }

    for(ll i=0; i<n; i++)
    {
        cout << a[i]+add[i] << " ";
    }
    cout << endl;

    return 0;
}