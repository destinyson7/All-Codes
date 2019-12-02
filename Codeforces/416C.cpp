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

    ll n;
    cin >> n;

    vector <ll> c, p;

    vector <bool> taken(n+5, false);

    for(ll i=0; i<n; i++)
    {
        ll a, b;
        cin >> a >> b;

        c.pb(a);
        p.pb(b);
    }

    ll k;
    cin >> k;

    vector <pll> r;

    for(ll i=0; i<k; i++)
    {
        ll a;
        cin >> a;

        r.pb(mp(a, i));
    }

    sort(all(r));
    ll acr = 0, money = 0;

    vector <ll> ans(k, -1);

    for(ll i=0; i<k; i++)
    {
        ll cur = r[i].ff;
        ll m = -1;
        ll which = -1;

        for(ll j=0; j<n; j++)
        {
            if(!taken[j] && c[j] <= cur)
            {
                if(p[j] > m)
                {
                    m = p[j];
                    which = j;
                }
            }
        }

        if(m != -1)
        {
            acr++;
            money+=m;
            taken[which] = true;
            ans[r[i].ss] = which;
        }
    }

    cout << acr << " " << money << endl;

    for(ll i=0; i<k; i++)
    {
        if(ans[i] != -1)
        {
            cout << ans[i]+1 << " " << i+1 << endl;
        }
    }

    return 0;
}