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

void solve()
{
    ll n;
    cin >> n;

    vector <ll> b;
    vector <ll> ans(2*n+5, 0);

    vector <ll> remaining;

    set <ll> in;

    bool f = true;

    for(ll i=0; i<n; i++)
    {
        ll x;
        cin >> x;

        b.pb(x);
        ans[2*i] = x;

        in.insert(x);
    }

    for(ll i=1; i<=2*n; i++)
    {
        if(in.find(i) == in.end())
        {
            remaining.pb(i);
        }
    }

    for(ll i=0; i<n; i++)
    {
        ll where = lower_bound(all(remaining), ans[2*i]) - remaining.begin();

        ll len = sz(remaining);

        if(where < len)
        {
            vector <ll> next;
            ans[2*i + 1] = remaining[where];

            for(auto j: remaining)
            {
                if(ans[2*i + 1] != j)
                {
                    next.pb(j);
                }
            }

            remaining = next;
        }

        else
        {
            cout << -1 << endl;
            return;
        }
    }

    for(ll i=0; i<n; i++)
    {
        if(min(ans[2*i], ans[2*i+1]) != b[i])
        {
            cout << -1 << endl;
            return;
        }
    }

    for(ll i=0; i<2*n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}