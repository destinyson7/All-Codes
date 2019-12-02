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

bool visited[L][L];
ll mat[L][L];

ll cnt = 0;

ll N, M;

bool isValid(ll x, ll y)
{
    if(x>=0 && y>=0 && x<N && y<M && mat[x][y] == 1)
    {
        return true;
    }

    return false;
}

void bfs(ll x, ll y)
{
    assert(!visited[x][y]);
    visited[x][y] = true;

    queue <pll> q;
    q.push(mp(x, y));

    vector <ll> dx = {1, 1, 0, -1, -1, -1, 0, 1};
    vector <ll> dy = {0, 1, 1, 1, 0, -1, -1, -1};

    while(!q.empty())
    {
        cnt++;
        pll top = q.front();
        q.pop();

        for(ll i=0; i<8; i++)
        {
            ll gx = top.ff + dx[i];
            ll gy = top.ss + dy[i];

            // cout << gx << " " << gy << " " << x << " " << y << endl;

            if(isValid(gx, gy) && !visited[gx][gy])
            {
                visited[gx][gy] = true;
                q.push(mp(gx, gy));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        // ll N, M;
        cin >> N >> M;

        ll tot = 0;
        ll m = 0;

        for(ll i=0; i<N; i++)
        {
            for(ll j=0; j<M; j++)
            {
                visited[i][j] = false;
                cin >> mat[i][j];
            }
        }

        for(ll i=0; i<N; i++)
        {
            for(ll j=0; j<M; j++)
            {
                if(!visited[i][j] && mat[i][j] == 1)
                {
                    // cout << i << " " << j << endl;
                    cnt = 0;
                    bfs(i, j);
                    m = max(m, cnt);
                    tot++;
                }
            }
        }

        cout << tot << " " << m << endl;
    }

    return 0;
}