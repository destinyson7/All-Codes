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

const ll L = 3e2+5;

ll r, c;

ll mat[L][L];

void solve()
{
    r = nxt(), c = nxt();

    for(ll i=0; i<r; i++)
    {
        for(ll j=0; j<c; j++)
        {
            cin >> mat[i][j];
        }
    }

    ll ans = 0;

    bool done = false;

    while(!done)
    {
        done = true;
        for(ll i=0; i<r; i++)
        {
            for(ll j=0; j<c; j++)
            {
                if(j == c-1)
                {
                    continue;
                }

                ll add = max(0LL, mat[i][j+1] - 1 - mat[i][j]);

                if(add > 0)
                {
                    done = false;
                }

                mat[i][j] += add;
                ans += add;
            }

            for(ll j=c-1; j>=0; j--)
            {
                if(j == 0)
                {
                    continue;
                }

                ll add = max(0LL, mat[i][j-1] - 1 - mat[i][j]);

                if(add > 0)
                {
                    done = false;
                }

                mat[i][j] += add;
                ans += add;
            }
        }

        for(ll j=0; j<c; j++)
        {
            for(ll i=0; i<r; i++)
            {
                if(i == r-1)
                {
                    continue;
                }

                ll add = max(0LL, mat[i+1][j] - 1 - mat[i][j]);

                if(add > 0)
                {
                    done = false;
                }

                mat[i][j] += add;
                ans += add;
            }

            for(ll i=r-1; i>=0; i--)
            {
                if(i == 0)
                {
                    continue;
                }

                ll add = max(0LL, mat[i-1][j] - 1 - mat[i][j]);

                if(add > 0)
                {
                    done = false;
                }

                mat[i][j] += add;
                ans += add;
            }
        }
    }

    cout << ans << endl;

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
