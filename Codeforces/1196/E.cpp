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

const ll M = 1e9;

vector <pll> store;

ll b = 0, w = 0;

void dfs(map <pll, bool> &visited, ll x, ll y, bool f)
{
    if(x > M || y > M || x < 1 || y < 1)
    {
        return;
    }

    if(visited[mp(x, y)] == true)
    {
        return;
    }

    if(!f)
    {
        if(w)
        {
            w--;
            visited[mp(x, y)] = true;
            dfs(visited, x-1, y, f^1);
            dfs(visited, x+1, y, f^1);
            dfs(visited, x, y+1, f^1);
            dfs(visited, x, y-1, f^1);
            
            store.pb(mp(x, y));
        }

        else
        {
            return;
        }
    }

    else
    {
        if(b)
        {
            b--;
            visited[mp(x, y)] = true;
            dfs(visited, x-1, y, f^1);
            dfs(visited, x+1, y, f^1);
            dfs(visited, x, y+1, f^1);
            dfs(visited, x, y-1, f^1);

            store.pb(mp(x, y));
        }

        else
        {
            return;
        }
    }

    // assert(false);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll q;
    cin >> q;

    while(q--)
    {
        store.clear();

        cin >> b >> w;

        map <pll, bool> visited;

        ll go = 5e8;

        dfs(visited, go, go, 0);

        if(b || w)
        {
            cout << "NO" << endl;
        }

        else
        {
            cout << "YES" << endl;

            for(ll i=0; i<sz(store); i++)
            {
                cout << store[i].ff << " " << store[i].ss << endl;
            }
        }
    }


    return 0;
}