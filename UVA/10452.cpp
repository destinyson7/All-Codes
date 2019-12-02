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

const ll L = 10+5;

ll grid[L][L];
ll visited[L][L];
pll par[L][L];

pll src;
pll des;

ll m, n;

bool dfs(ll i, ll j)
{
    // cout << i << " " << j << endl;

    if(mp(i, j) == des)
    {
        return true;
    }

    if(i == -1 || i == m || j == -1 || j == n)
    {
        return false;
    }

    if(visited[i][j] || !grid[i][j])
    {
        return false;
    }

    visited[i][j] = 1;

    if(dfs(i-1, j))
    {
        par[i-1][j] = mp(i, j);
        return true;
    }

    if(dfs(i, j+1))
    {
        par[i][j+1] = mp(i, j);
        return true;
    }

    if(dfs(i, j-1))
    {
        par[i][j-1] = mp(i, j);
        return true;
    }

    return false;    
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        cin >> m >> n;

        for(ll i=0; i<m; i++)
        {
            string s;
            cin >> s;

            for(ll j=0; j<n; j++)
            {
                if(s[j] == '@')
                {
                    src = mp(i, j);
                    grid[i][j] = 1;
                }

                else if(s[j] == '#')
                {
                    des = mp(i, j);
                    grid[i][j] = 1;
                }

                else if(s[j] == 'I' || s[j] == 'E' || s[j] == 'H' || s[j] == 'O' || s[j] == 'V' || s[j] == 'A')
                {
                    grid[i][j] = 1;
                }

                else
                {
                    grid[i][j] = 0;
                }

                visited[i][j] = 0;
            }
        }

        dfs(src.ff, src.ss);

        vector <string> ans;

        ll x = des.ff, y = des.ss;

        // cout << x << " " << y << endl;

        while(1)
        {
            // cout << "x " << x << " " << y << endl;
            if(mp(x, y) == src)
            {
                break;
            }

            if(x == par[x][y].ff)
            {
                if(y == par[x][y].ss + 1)
                {
                    ans.pb("right");
                }

                else
                {
                    ans.pb("left");
                }
            }

            else
            {
                ans.pb("forth");
            }
            
            pll temp = par[x][y];
            
            x = temp.ff;
            y = temp.ss;
        }

        reverse(all(ans));

        cout << ans[0];
        for(ll i=1; i<sz(ans); i++)
        {
            cout << " " << ans[i];
        }
        cout << endl;
    }

    return 0;
}