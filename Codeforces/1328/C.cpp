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
    ll n = nxt();

    string x;
    cin >> x;

    basic_string <ll> f, s;

    bool cur = 0;

    for(ll i=0; i<n; i++)
    {
        if(x[i] == '2')
        {
            if(!cur)
            {
                f += 1;
                s += 1;
            }

            else
            {
                f += 0LL;
                s += 2;
            }
        }

        else if(x[i] == '1')
        {
            if(!cur)
            {
                f += 1;
                s += 0LL;
                cur ^= 1;
            }

            else
            {
                f += 0LL;
                s += 1;
            }
        }

        else
        {
            f += 0LL;
            s += 0LL;
        }
    }

    ll st = 0;
    while(f[st] == 0)
    {
        st++;
    }

    for(ll i=st; i<n; i++)
    {
        cout << f[i];
    }
    cout << endl;

    st = 0;

    while(s[st] == 0)
    {
        st++;
    }

    for(ll i=st; i<n; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}