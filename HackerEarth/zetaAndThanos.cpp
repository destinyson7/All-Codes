#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef int ll;
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

const ll L = 1e3+1;

char mat[L][L];
ll dis[L][L];
ll val[L][L];
// bool visited[L][L];

ll N, M;

bool isValid(ll x, ll y)
{
    if(x > 0 && y > 0 && x <= N && y <= M && mat[x][y] != '*')
    {
        return true;
    }

    return false;
}

void bfs(ll sx, ll sy)
{
    // assert(!visited[sx][sy]);
    // visited[sx][sy] = 1;
    dis[sx][sy] = 0;
    val[sx][sy] = mat[sx][sy] - '0';

    vector <ll> dx = {-1, 1, 0, 0};
    vector <ll> dy = {0, 0, -1, 1};

    queue <pll> q;
    q.push(mp(sx, sy));

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        ll x = top.ff, y = top.ss;

        for(ll i=0; i<4; i++)
        {
            // if(isValid(x+dx[i], y+dy[i]) && !visited[x+dx[i]][y+dy[i]] && mat[x+dx[i]][y+dy[i]] != '*')
            // {
            //     visited[x+dx[i]][y+dy[i]] = true;
            //     q.push(mp(x+dx[i], y+dy[i]));

            //     dis[x+dx[i]][y+dy[i]] = dis[x][y] + 1;
            //     val[x+dx[i]][y+dy[i]] = max(val[x+dx[i]][y+dy[i]], val[x][y] + mat[x+dx[i]][y+dy[i]] - '0');

            //     // cout << x+dx[i] << " " << y+dy[i] << " " << val[x+dx[i]][y+dy[i]] << endl;
            // }

            // else if(isValid(x+dx[i], y+dy[i]) && (dis[x+dx[i]][y+dy[i]] == (dis[x][y] + 1)) && mat[x+dx[i]][y+dy[i]] != '*')
            // {
            //     val[x+dx[i]][y+dy[i]] = max(val[x+dx[i]][y+dy[i]], val[x][y] + mat[x+dx[i]][y+dy[i]] - '0');
            // }
            
            ll curx = x + dx[i], cury = y + dy[i];
            // cout << curx << " " << cury << endl;
            if(isValid(curx, cury) && dis[x][y] != 1e15)
            {
                if(dis[curx][cury] > dis[x][y] + 1)
                {
                    dis[curx][cury] = dis[x][y] + 1;
                    val[curx][cury] = val[x][y] + (ll)(mat[curx][cury] - '0');
                    q.push(mp(curx, cury));
                }

                else if(dis[curx][cury] == dis[x][y] + 1 && val[curx][cury] < val[x][y])
                {
                    val[curx][cury] = val[x][y] + (ll)(mat[curx][cury] - '0');
                    q.push(mp(curx, cury));
                }
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // ll N, M;
    cin >> N >> M;

    for(ll i=1; i<=N; i++)
    {
        for(ll j=1; j<=M; j++)
        {
            cin >> mat[i][j];
            dis[i][j] = INT_MAX;
            val[i][j] = 0;
        }
    }

    ll X, Y;
    cin >> X >> Y;

    // X--, Y--;

    bfs(X , Y);

    ll Q;
    cin >> Q;

    while(Q--)
    {
        ll x, y;
        cin >> x >> y;

        // x--, y--;

        if(mat[x][y] == '*')
        {
            cout << -1 << " " << -1 << endl;
            // return 0;
        }

        if(dis[x][y] == 1e15)
        {
            cout << -1 << " " << -1 << endl;
        }

        else
        {
            cout << dis[x][y] << " " << val[x][y] << endl;
        }
    }

    return 0;
}