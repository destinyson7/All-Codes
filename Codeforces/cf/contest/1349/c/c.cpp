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
vector <string> grid;
ll can[L][L];
ll mi[L][L];
ll n, m, t;

vector <ll> dx = {-1, 0, 1, 0};
vector <ll> dy = {0, 1, 0, -1};

bool check(ll a, ll b)
{
    return (a < n && a >= 0 && b < m && b >= 0);
}

void solve()
{
    n = nxt(), m = nxt(), t = nxt();

    queue <pll> q;

    for(ll i=0; i<n; i++)
    {
        string s;
        cin >> s;

        grid.pb(s);

        // for(ll j=0; j<m; j++)
        // {
        //     if(s[j] == '1')
        //     {
        //         disb[i][j] = 1e9;
        //     }

        //     else
        //     {
        //         q.push(mp(i, j));
        //         vis[i][j] = true;
        //         disb[i][j] = 0;
        //     }
        // }
    }

    // while(!q.empty())
    // {
    //     ll i = q.front().ff;
    //     ll j = q.front().ss;

    //     q.pop();

    //     for(ll k=0; k<4; k++)
    //     {
    //         ll x = i + dx[k];
    //         ll y = j + dy[k];

    //         if(check(x, y) && !vis[x][y])
    //         {
    //             vis[x][y] = true;
    //             // if(grid[x][y] == '1')
    //             // {
    //                 disb[x][y] = disb[i][j] + 1;
    //             // }
    //             q.push(mp(x, y));
    //         }
    //     }
    // }

    // while(!q.empty())
    // {
    //     q.pop();
    // }

    // for(ll i=0; i<n; i++)
    // {
    //     for(ll j=0; j<m; j++)
    //     {
    //         vis[i][j] = false;

    //         if(grid[i][j] == '1')
    //         {
    //             disw[i][j] = 0;
    //             vis[i][j] = true;
    //             q.push(mp(i, j));
    //         }

    //         else
    //         {
    //             disw[i][j] = 1e9;
    //         }
    //     }
    // }

    // while(!q.empty())
    // {
    //     ll i = q.front().ff;
    //     ll j = q.front().ss;

    //     q.pop();

    //     for(ll k=0; k<4; k++)
    //     {
    //         ll x = i + dx[k];
    //         ll y = j + dy[k];

    //         if(check(x, y) && !vis[x][y])
    //         {
    //             vis[x][y] = true;
    //             // if(grid[x][y] == '0')
    //             // {
    //                 disw[x][y] = disw[i][j] + 1;
    //             // }
    //             q.push(mp(x, y));
    //         }
    //     }
    // }

    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            for(ll k=0; k<4; k++)
            {
                ll x = i + dx[k], y = j + dy[k];

                if(check(x, y) && grid[x][y] == grid[i][j])
                {
                    can[i][j] = 1;
                }
            }

            if(can[i][j])
            {
                mi[i][j] = 0;
                pq.push(mp(0, mp(i, j)));
            }

            else
            {
                mi[i][j] = 1e18;
            }
        }
    }
    
    while(!pq.empty())
    {
        ll i = pq.top().ss.ff, j = pq.top().ss.ss;
        ll val = pq.top().ff;

        pq.pop();

        for(ll k=0; k<4; k++)
        {
            ll x = i + dx[k], y = j + dy[k];

            if(check(x, y) && grid[x][y] != grid[i][j] && !can[x][y])
            {
                mi[x][y] = val+1;
                can[x][y] = 1;
                pq.push(mp(mi[x][y], mp(x, y)));
            }
        }
    }

    while(t--)
    {
        ll i = nxt() - 1, j = nxt() - 1;
        ll p = nxt();

        if(p <= mi[i][j])
        {
            cout << grid[i][j] << endl;
            continue;
        }

        ll rem = p - mi[i][j];

        if(rem % 2 == 0)
        {
            cout << grid[i][j] << endl;
        }

        else
        {
            if(grid[i][j] == '1')
            {
                cout << 0 << endl;
            }

            else
            {
                cout << 1 << endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    // T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}