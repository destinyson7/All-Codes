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

const ll L = 1e2+5;

bool f = false;

ll visited[L][L];
ll grid[L][L];

ll N;

void dfs(ll i, ll j)
{
    if(i>=N || j>=N || i<0 || j<0)
    {
        return;
    }

    if(visited[i][j] || !grid[i][j])
    {
        return;
    }

    if(grid[i][j] == 1)
    {
        f = true;
    }

    visited[i][j] = true;

    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    for(ll t=1; t<=T; t++)
    {
        // ll N;
        cin >> N;

        for(ll i=0; i<N; i++)
        {
            for(ll j=0; j<N; j++)
            {
                char c;
                cin >> c;

                if(c == 'x')
                {
                    grid[i][j] = 1;
                }

                else if(c == '@')
                {
                    grid[i][j] = 2;
                }

                else
                {
                    grid[i][j] = 0;
                }

                visited[i][j] = false;
            }
        }

        ll cnt = 0;

        for(ll i=0; i<N; i++)
        {
            for(ll j=0; j<N; j++)
            {
                if(!visited[i][j] && grid[i][j])
                {
                    f = false;
                    dfs(i, j);
                    
                    if(f)
                    {
                        cnt++;
                    }
                }
            }
        }

        cout << "Case " << t << ": " << cnt << endl;
    }


    return 0;
}