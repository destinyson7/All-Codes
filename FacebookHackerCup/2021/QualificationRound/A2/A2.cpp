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

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 50;

// vector <ll> adj[L];
ll d[L][L];

void solve()
{
    string s;
    cin >> s;

    ll kk = nxt();

    for(ll i = 0; i < L; i++)
    {
        for(ll j = 0; j < L; j++)
        {
            d[i][j] = 1e15;

            if(i == j)
            {
                d[i][j] = 0;
            }
        }

        // adj[i].clear();
    }

    for(ll i = 0; i < kk; i++)
    {
        string a;
        cin >> a;

        // adj[a[0] - 'A'].pb(a[1] - 'A');
        d[a[0] - 'A'][a[1] - 'A'] = 1;
    }

    for(ll k = 0; k < L; k++)
    {
        for(ll i = 0; i < L; i++)
        {
            for(ll j = 0; j < L; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    ll n = sz(s);
    ll ans = 1e15;

    for(ll i = 0; i < L; i++)
    {
        ll cur = 0;

        for(ll j = 0; j < n; j++)
        {
            if(d[s[j] - 'A'][i] > 1e12)
            {
                cur = 1e15;
                break;
            }

            cur += d[s[j] - 'A'][i];
        }

        ans = min(cur, ans);
    }

    if(ans > 1e12)
    {
        cout << -1 << endl;
    }

    else
    {
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    for(ll i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
