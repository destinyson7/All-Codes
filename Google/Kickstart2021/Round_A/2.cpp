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

const ll L = 1e3+5;

ll mat[L][L];
ll rows[L][L];
ll cols[L][L];

ll r, c;

ll add()
{
    ll ans = 0;

    for(ll i=1; i<=r; i++)
    {
        for(ll j=1; j<=c; j++)
        {
            if(cols[i][j] >= 4)
            {
                ans += max(0LL, min(cols[i][j]/2 - 1, rows[i][j] - 1));
                // cout << vector <ll> {ans, i, j, rows[i][j], cols[i][j], 1} << endl;
            }

            if(rows[i][j] >= 4)
            {
                ans += max(0LL, min(cols[i][j] - 1, rows[i][j]/2 - 1));
                // cout << vector <ll> {ans, i, j, rows[i][j], cols[i][j], 2} << endl;
            }
        }
    }

    return ans;
}

void solve()
{
    r = nxt(), c = nxt();

    for(ll i=0; i<=r+1; i++)
    {
        for(ll j=0; j<=c+1; j++)
        {
            mat[i][j] = 0;
            rows[i][j] = 0;
            cols[i][j] = 0;
        }
    }

    for(ll i=1; i<=r; i++)
    {
        for(ll j=1; j<=c; j++)
        {
            cin >> mat[i][j];
        }
    }

    for(ll i=1; i<=r; i++)
    {
        for(ll j=1; j<=c; j++)
        {
            if(mat[i][j] == 0)
            {
                rows[i][j] = 0;
            }

            else
            {
                rows[i][j] = rows[i][j-1] + 1;
            }
        }
    }

    for(ll j=1; j<=c; j++)
    {
        for(ll i=1; i<=r; i++)
        {
            if(mat[i][j] == 0)
            {
                cols[i][j] = 0;
            }

            else
            {
                cols[i][j] = cols[i-1][j] + 1;
            }
        }
    }

    ll ans = add();

    for(ll i=1; i<=r; i++)
    {
        for(ll j=c; j>=1; j--)
        {
            if(mat[i][j] == 0)
            {
                rows[i][j] = 0;
            }

            else
            {
                rows[i][j] = rows[i][j+1] + 1;
            }
        }
    }

    ans += add();

    for(ll j=1; j<=c; j++)
    {
        for(ll i=r; i>=1; i--)
        {
            if(mat[i][j] == 0)
            {
                cols[i][j] = 0;
            }

            else
            {
                cols[i][j] = cols[i+1][j] + 1;
            }
        }
    }

    ans += add();

    for(ll i=1; i<=r; i++)
    {
        for(ll j=1; j<=c; j++)
        {
            if(mat[i][j] == 0)
            {
                rows[i][j] = 0;
            }

            else
            {
                rows[i][j] = rows[i][j-1] + 1;
            }
        }
    }

    ans += add();

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
