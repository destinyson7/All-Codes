#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 20+5;

char grid[L][L];
ll visited[L][L];

ll M, N;

ll cur = 0;
char h = '0';

void dfsF(ll i, ll j)
{
    if(j < 0)
    {
        j = N-1;
    }

    if(j > N-1)
    {
        j = 0;
    }

    if(i < 0 || i > M-1)
    {
        return;
    }

    if(grid[i][j] != h || visited[i][j])
    {
        return;
    }

    grid[i][j] = h+1;
    visited[i][j] = true;

    dfsF(i+1, j);
    dfsF(i, j+1);
    dfsF(i-1, j);
    dfsF(i, j-1);
}

void dfsS(ll i, ll j)
{
    if(j < 0)
    {
        j = N-1;
    }

    if(j > N-1)
    {
        j = 0;
    }

    if(i < 0 || i > M-1)
    {
        return;
    }

    if(visited[i][j] || grid[i][j] != h)
    {
        return;
    }

    cur++;
    visited[i][j] = true;

    dfsS(i+1, j);
    dfsS(i, j+1);
    dfsS(i-1, j);
    dfsS(i, j-1);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    // ll M, N;

    while(cin >> M >> N)
    {
        for(ll i=0; i<M; i++)
        {
            string s;
            cin >> s;

            for(ll j=0; j<N; j++)
            {
                grid[i][j] = s[j];

                visited[i][j] = false;
            }
        }

        ll X, Y;
        cin >> X >> Y;

        h = grid[X][Y];

        dfsF(X, Y);

        ll ans = 0;

        for(ll i=0; i<M; i++)
        {
            for(ll j=0; j<N; j++)
            {
                if(grid[i][j] == h && !visited[i][j])
                {
                    cur = 0;

                    dfsS(i, j);

                    ans = max(cur, ans);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}