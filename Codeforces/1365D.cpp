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

const ll L = 50+5;
ll n, m;
char mat[L][L];
bool visited[L][L];
bool can[L][L];
ll good = 0;

vector <ll> dx = {1, 0, -1, 0};
vector <ll> dy = {0, -1, 0, 1};

void dfs(ll i, ll j)
{
    if(i < 0 || j < 0 || i >= n || j >= m || !can[i][j])
    {
        return;
    }

    assert(!visited[i][j]);
    visited[i][j] = true;

    if(mat[i][j] == 'G')
    {
        good--;
    }

    for(ll k = 0; k < 4; k++)
    {
        ll new_i = i + dx[k], new_j = j + dy[k];
        if(!visited[new_i][new_j])
        {
           dfs(new_i, new_j);
        }
    }
}

void solve()
{
    n = nxt(), m = nxt();

    good = 0;

    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            visited[i][j] = false;
            can[i][j] = 1;

            if(mat[i][j] == 'G')
            {
                good++;
            }
        }
    }

    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            if(mat[i][j] == '#')
            {
                can[i][j] = 0;
            }

            else if(mat[i][j] == 'B')
            {
                if(i - 1 >= 0)
                {
                    can[i - 1][j] = 0;
                }

                if(i + 1 < n)
                {
                    can[i + 1][j] = 0;
                }

                if(j - 1 >= 0)
                {
                    can[i][j - 1] = 0;
                }

                if(j + 1 < m)
                {
                    can[i][j + 1] = 0;
                }
            }
        }
    }

    dfs(n - 1, m - 1);

    if(good == 0)
    {
        cout << "Yes" << endl;
    }

    else
    {
        cout << "No" << endl;
    }

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
