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

const ll L = 1e3+5;
char mat[L][L];
ll dis[L][L];
pll par[L][L];

ll n, m;

vector <ll> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector <ll> dy = {1, 0, -1, 0, 1, -1, -1, 1};

bool isValid(ll x, ll y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != 'X');
}

void bfs(pll src)
{
    queue <pll> q;
    q.push(src);

    dis[src.ff][src.ss] = 0;

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        for(ll i=0; i<8; i++)
        {
            ll x = top.ff + dx[i];
            ll y = top.ss + dy[i];

            while(isValid(x, y))
            {
                if(dis[x][y] != -1 && dis[x][y] <= dis[top.ff][top.ss])
                {
                    break;
                }

                if(dis[x][y] == -1)
                {
                    q.push(mp(x, y));
                }

                if(dis[x][y] == -1)
                {
                    dis[x][y] = dis[top.ff][top.ss] + 1;
                }

                // cout << top << " " << mp(x, y) << " " << dis[top.ff][top.ss] << " " << dis[x][y] << endl;
                
                x += dx[i];
                y += dy[i];
            }
        }
    }
}

void solve()
{
    // ll n, m;
    cin >> n >> m;

    pll start, end;

    for(ll i=0; i<n; i++)
    {   
        string s;
        cin >> s;

        for(ll j=0; j<m; j++)
        {
            mat[i][j] = s[j];
            // visited[i][j] = false;
            dis[i][j] = -1;
            par[i][j] = mp(-1, -1);

            if(s[j] == 'S')
            {
                start = mp(i, j);
                // visited[i][j] = true;
            }

            else if(s[j] == 'F')
            {
                end = mp(i, j);
            }

            else if(s[j] == 'X')
            {
                // dp nothing
                // visited[i][j] = true;
            }

            else if(s[j] == '.')
            {
                // do nothing
            }

            else
            {
                assert(false);
            }
        }
    }

    bfs(start);

    cout << dis[end.ff][end.ss] << endl;
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