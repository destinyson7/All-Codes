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

const ll L = 180+5;

ll mat[L][L];
ll dis[L][L];

queue <pll> q;

ll n, m;
bool isValid(ll x, ll y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }

    return true;
}

vector <ll> dx = {-1, 0, 1, 0};
vector <ll> dy = {0, 1, 0, -1};

void bfs()
{
    while(!q.empty())
    {
        ll x = q.front().ff;
        ll y = q.front().ss;

        q.pop();

        for(ll i=0; i<4; i++)
        {
            if(isValid(x+dx[i], y+dy[i]) && dis[x+dx[i]][y+dy[i]] == 1e15)
            {
                dis[x+dx[i]][y+dy[i]] = 1 + dis[x][y];
                q.push(mp(x+dx[i], y+dy[i]));
            }
        }
    }
}

void solve()
{
    while(!q.empty())
    {
        q.pop();
    }

    // ll n, m;
    cin >> n >> m;

    for(ll i=0; i<n; i++)
    {
        string s;
        cin >> s;

        for(ll j=0; j<m; j++)
        {
            if(s[j] == '1')
            {
                q.push(mp(i, j));
                mat[i][j] = 1;
                dis[i][j] = 0;
            }

            else
            {
                mat[i][j] = 0;
                dis[i][j] = 1e15;
            }
        }
    }

    bfs();

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
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