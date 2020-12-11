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

#define pb push_backs
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

void solve()
{
    ll n = nxt(), a = nxt(), b = nxt(), c = nxt();

    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }

    if(n == 2)
    {
        if(c == 2)
        {
            cout << "1 1" << endl;
            return;
        }

        else
        {
            if(a == 1 && b == 1)
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }

            else if(a == 1)
            {
                cout << "2 1" << endl;
                return;
            }

            else
            {
                cout << "1 2" << endl;
                return;
            }
        }
    }

    basic_string <ll> ans;
    
    ans += 2;

    for(ll i=0; i<a-c-1; i++)
    {
        ans += 2;
    }

    for(ll i=0; i<c; i++)
    {
        ans += 3;
    }

    for(ll i=0; i<n-(a+b-c); i++)
    {
        ans += 1;
    }

    for(ll i=0; i<b-c; i++)
    {
        ans += 2;
    }

    // bool f = false;

    // if(a > b)
    // {
    //     swap(a, b);
    //     f = true;
    // }

    // ans += 2;

    //     for(ll i=0; i<a-c+1; i++)
    //     {
    //        ans += 2;
    //     }

    //     for(ll i=0; i<c-1; i++)
    //     {
    //         ans += 3;
    //     }

    //     for(ll i=0; i<n-(a+b-c); i++)
    //     {
    //         ans += 1;
    //     }

    //     for(ll i=0; i<b-c; i++)
    //     {
    //         ans += 2;
    //     }
    // if(f)
    // {
    //     reverse(all(ans));
    // }

    // if(sz(ans) != n)
    // {
    //     cout << "IMPOSSIBLE" << endl;
    // }

    // set <ll> s1, s2;

    // ll first = ans[0];
    // s1.insert(0);

    // for(ll i=1; i<n; i++)
    // {

    // }

    for(ll i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;


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