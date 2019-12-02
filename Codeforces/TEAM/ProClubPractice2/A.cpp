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

    ll T;
    cin >> T;

    while(T--)
    {
        ll n, m, k;
        cin >> n >> m >> k;

        string a, b;
        cin >> a >> b;

        if(k == 1)
        {
            vector <ll> cnt(30, 0);

            for(ll i=0; i<m; i++)
            {
                cnt[b[i]-97]++;
            }

            ll ans = 0;

            for(ll i=0; i<n; i++)
            {
                ans += cnt[a[i]-97];
            }

            cout << ans << endl;

            continue;
        }

        vector <pair <char, char>> p;

        for(ll i=0; i<n-k+1; i++)
        {
            p.pb(mp(a[i], a[i+k-1]));
        }

        // sort(all(p));

        vector <ll> adj[30];

        for(ll i=0; i<m; i++)
        {
            adj[b[i]-97].pb(i);
        }

        ll len = sz(p);

        ll ans = 0;

        for(ll i=0; i<len; i++)
        {
            char f = p[i].ff, s = p[i].ss;

            cout << f << s << endl;

            for(auto j: adj[f-97])
            {
                ans += (sz(adj[s-97]) - (upper_bound(all(adj[s-97]), j) - adj[s-97].begin()));
                cout << "* " << ans << " * " << (lower_bound(all(adj[s-97]), j) - adj[s-97].begin()) << endl;
            }
        }

        cout << ans << endl;
    }

    return 0;
}