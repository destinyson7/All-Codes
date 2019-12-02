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

const ll L = 25+5;

ll grid[L][L];
ll visited[L][L];

void dfs(ll i, ll j, ll n)
{
    if(i==-1 || j==-1 || i==(n+1) || j==(n+1))
    {
        return;
    }

    if(!grid[i][j] || visited[i][j])
    {
        return;
    }

    visited[i][j] = 1;

    dfs(i-1, j, n);
    dfs(i-1, j+1, n);
    dfs(i, j+1, n);
    dfs(i+1, j+1, n);
    dfs(i+1, j, n);
    dfs(i+1, j-1, n);
    dfs(i, j-1, n);
    dfs(i-1, j-1, n);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll n;

    ll cur = 0;

    while(cin >> n)
    {
        cin.ignore();

        cur++;

        for(ll i=0; i<n; i++)
        {
            string s;
            cin >> s;

            for(ll j=0; j<n; j++)
            {
                grid[i][j] = s[j]-'0';
                visited[i][j] = false;
            }
        }

        ll comp = 0;

        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                if(grid[i][j] && !visited[i][j])
                {
                    comp++;

                    dfs(i, j, n);
                }
            }
        }

        cout << "Image number " << cur << " contains " << comp << " war eagles" << endl;
    }



    return 0;
}