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

const ll L = 1e5+5;

void solve()
{
    ll n = nxt(), k = nxt();

    basic_string <ll> s(k, 0);
    generate(all(s), nxt);

    ll a1 = nxt(), a2 = nxt(), a3 = nxt(), a4 = nxt();

    basic_string <ll> x(k, 0);
    generate(all(x), nxt);

    ll b1 = nxt(), b2 = nxt(), b3 = nxt(), b4 = nxt();

    basic_string <ll> y(k, 0);
    generate(all(y), nxt);

    ll c1 = nxt(), c2 = nxt(), c3 = nxt(), c4 = nxt();

    for(ll i=k; i<n; i++)
    {
        s += (a1 * s[i-2] + a2 * s[i-1] + a3) % a4;
        x += (b1 * x[i-2] + b2 * x[i-1] + b3) % b4;
        y += (c1 * y[i-2] + c2 * y[i-1] + c3) % c4;
    }

    // cout << s << endl << x << endl << y << endl;    

    ll can = 0;
    ll extra = 0;
    ll empty = 0;

    ll more = 0;
    ll less = 0;

    for(ll i=0; i<n; i++)
    {
        if(s[i] >= (x[i] + y[i]))
        {
            extra += (s[i] - (x[i] + y[i]));
            more += (s[i] - x[i] - y[i]);
            can += y[i];
        }

        else if(s[i] >= x[i])
        {
            can += (s[i] - x[i]);
            empty += (x[i] + y[i] - s[i]);
        }

        else
        {
            extra -= (x[i] - s[i]);
            empty += y[i];
            less += (x[i] - s[i]);
        }

        // cout << can << " " << extra << " " << empty << " " << more << " " << less << endl;
    }   

    if(extra == 0)
    {
        cout << more << endl;
        return;
    }

    else if(extra > 0)
    {
        if(empty < extra)
        {
            cout << -1 << endl;
            return;
        }

        else
        {
            cout << max(more, less) << endl;
            return;
        }
    }

    else
    {
        if(can < -extra)
        {
            cout << -1 << endl;
            return;
        }

        else
        {
            cout << max(more, less) << endl;
            return;
        }   
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    for(ll i=1; i<=T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}