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

const ll L = 1e5 + 5;

void solve()
{
    ll r, c, k;
    cin >> r >> c >> k;

    vector <vector <ll>> grid(r + 5, vector <ll> (c + 5, 0));
    // vector <vector <ll>> upsum(r + 5, vector <ll> (c + 5, 0));
    // vector <vector <ll>> downsum(r + 5, vector <ll> (c + 5, 0));

    vector <ll> taken(c + 5, 0);
    ll ans = 1e18;

    for(ll i = 1; i <= r; i++)
    {
        for(ll j = 1; j <= c; j++)
        {
            char temp;
            cin >> temp;

            if(temp == 'X')
            {
                grid[i][j] = 1;
                taken[i]++;
            }

            else
            {
                grid[i][j] = 0;
            }
        }

    }

    ans = min(ans, taken[k]);

    vector <ll> at = grid[k];

    // for(ll j = 1; j <= c; j++)
    // {
    //     for(ll i = 1; i <= r; i++)
    //     {
    //         upsum[i][j] = upsum[i - 1][j] + grid[i][j];
    //     }
    // }

    // for(ll j = 1; j <= c; j++)
    // {
    //     for(ll i = r; i >= 1; i--)
    //     {
    //         downsum[i][j] = downsum[i - 1][j] + downsum[i][j];
    //     }
    // }


    for(ll i = 1; i <= k - 1; i++)
    {
        ll cur_ans = 0;

        for(ll j = 1; j <= c; j++)
        {
            if(grid[k - i][j] == 0)
            {
                at[j]--;
                at[j] = max(0LL, at[j]);
            }

            if(grid[min(r + 1, k + i)][j] == 1)
            {
                at[j]++;
            }

            cur_ans += (at[j] > 0);
        }

        cout << "up " << k - i << " " << cur_ans << endl;

        ans = min(ans, cur_ans + i);
    }

    at = grid[k];

    for(ll i = 1; i <= r - k; i++)
    {
        ll cur_ans = 0;

        for(ll j = 1; j <= c; j++)
        {
            if(grid[k + i][j] == 0)
            {
                at[j]--;
                at[j] = max(0LL, at[j]);
            }

            if(grid[max(0LL, k - i)][j] == 1)
            {
                at[j]++;
            }

            cur_ans += (at[j] > 0);
        }

        cout << "down " << k + i << " " << cur_ans << endl;

        ans = min(ans, cur_ans + i);
    }


    cout << ans << endl;

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
