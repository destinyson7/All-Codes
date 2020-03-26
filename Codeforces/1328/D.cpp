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

const ll L = 2e5+5;

void solve()
{
    ll n = nxt();
    basic_string <ll> t(n, 0);
    generate(all(t), nxt);

    set <ll> s(all(t));

    basic_string <ll> ans(n, 0);

    if(sz(s) == 1)
    {
        ans = basic_string <ll>(n, 1);
        cout << 1 << endl;
    }

    else
    {
        ans[0] = 1;
        ll pos = -1;

        for(ll i=1; i<n; i++)
        {
            if(t[i-1] == t[i])
            {
                pos = i;
                ans[i] = ans[i-1];
            }

            else if(ans[i-1] == 1)
            {
                ans[i] = ans[i-1] + 1;
            }

            else
            {
                ans[i] = 1;
            }
        }

        if(t[0] != t[n-1] && ans[n-1] == 1)
        {
            if(pos != -1)
            {
                if(ans[pos-1] == 1)
                {
                    ans[pos] = ans[pos-1] + 1;
                }

                else
                {
                    ans[pos] = 1;
                }

                for(ll i = pos+1; i<n; i++)
                {
                    if(t[i-1] == t[i])
                    {
                        pos = i;
                        ans[i] = ans[i-1];
                    }

                    else if(ans[i-1] == 1)
                    {
                        ans[i] = ans[i-1] + 1;
                    }

                    else
                    {
                        ans[i] = 1;
                    }
                }

                cout << 2 << endl;
            }

            else
            {
                ans[n-1] = 3;

                cout << 3 << endl;
            }
        }

        else
        {
            cout << 2 << endl;
        }
    }

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

    while(T--)
    {
        solve();
    }

    return 0;
}